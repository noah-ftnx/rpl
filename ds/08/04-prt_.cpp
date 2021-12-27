#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct Node {
  map<char, Node*> child;
  bool leaf = false;
  bool has(char c) { return child.contains(c); }
  void put(char c) { child.insert(make_pair(c, new Node())); }
  Node* get(char c) { return child[c]; }
};

struct Trie {
  Node* root = new Node();

  void insert(string s) {
    auto node = root;
    for (auto c: s) {
      if (!node->has(c)) node->put(c);
      node=node->get(c);
    }
    node->leaf=true;
  }

  void _get_words(vector<string>& words, Node* node, string word) {
   if (node->leaf) { words.push_back(word); }

   for (auto pair: node->child) {
     _get_words(words, pair.second, word + pair.first) ;
   }
  }

  vector<string> get_words() {
    vector<string> words;
    _get_words(words, root, "");
    return words;
  }

};



#include "test/04.h"
int main() { run_tests(); return 0; }