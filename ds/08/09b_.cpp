#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
  unordered_map<char, Node*> child {};
  vector<int> indexes {};
  bool leaf {};

  bool has(char c) { return child.contains(c); }
  void put(char c, int idx) {
    if (!has(c)) child.insert(make_pair(c, new Node()));
    indexes.push_back(idx);
  }

  Node* get(char c) { return has(c)?child[c]:nullptr; }
};

struct WordFilter {
  Node* root = new Node();
  vector<string> dict;
  WordFilter(vector<string>& words) {
    dict=words;
    unordered_set<string> unq;
    for (int i=words.size()-1; i>=0; i--) {
      string word = words[i];
      if (unq.insert(word).second) {
        insert_with_suffix(word, i);
      }
    }
  }

  void insert_with_suffix(const string& word, int idx) {
    // abc
    // c#abc     : must be added in this order, otherwise
    // bc#abc      the suffix would have to be reversed in f()
    // abc#abc
    string suffix="";
    for(int i=word.size()-1; i>=0; i--) {
      suffix=word[i]+suffix;
      string sfx_word = suffix + "#" + word;
      insert(sfx_word, idx);
    }
  }

  void insert(const string& word, int idx) {
    auto node = root;
    for (auto c: word) {
      node->put(c, idx);
      node=node->get(c);
    }
    node->leaf=true;
  }

  int f(string prefix, string suffix) {
    string query = suffix + "#" + prefix;
    auto node = root;
    for (auto c: query) {
      if (!node->has(c)) return -1;
      node=node->get(c);
    }
    return node->indexes.front();
  }
};



#include "test/09.h"
int main() { run_tests(); return 0; }