#include <unordered_map>
#include <vector>
#include <string>
#include <set>
using namespace std;

struct Node {
  unordered_map<char, Node*> child;
  vector<int> indices;
  bool leaf = false;
  bool has(char c) { return child.contains(c); }
  void put(char c, int idx) {
    if (!has(c)) child.insert(make_pair(c, new Node()));
    indices.push_back(idx);
  }
  Node* get(char c) { return child[c]; }
};

struct WordFilter {
  Node* root {};
  vector<string> dict;

  void insert(string s, int idx) {
    auto node = root;
    for (auto c: s) {
      node->put(c, idx);
      node=node->get(c);
    }
    node->leaf=true;
  }

  WordFilter(vector<string>& words) {
    dict = words;
    root = new Node();
    // add only the last occurrence of a word + it's index
    set<string> unq;
    for (int i=words.size()-1; i>=0; i--) { // O(W L): W: words.size, L: largest word size
      const string word = words[i];
      if (unq.insert(word).second) {
        insert(word, i);
      }
    }
  }

  int f(string prefix, string suffix) {
    auto node = root;
    for (auto c: prefix) { // O(P)
      if (!node->has(c)) return -1;
      node=node->get(c);
    }

    for (auto i: node->indices) { // O(W S): W: words.size, S: suffix.size
      string word = dict[i];
      if (suffix.size() > word.size()) continue;

      // abccFF
      // FF
      bool match=true;
      for (int j=0; match && j<suffix.size(); j++) {
        match = suffix[suffix.size()-1-j]==word[word.size()-1-j];
      }
      if (match) return i; // found index
    }
    return -1;
  }
};



#include "test/09.h"
int main() { run_tests(); return 0; }