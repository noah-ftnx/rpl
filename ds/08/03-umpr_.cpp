#include <unordered_map>
#include <iostream>
using namespace std;

struct Node {
  unordered_map<char, Node*> child;
  bool leaf {};
};

struct Trie {
  Node* root = new Node();

  void _insert(Node* node, const string& s, int idx) {
    if (idx == s.size()) { node->leaf = true; return; }
    const char c = s[idx];
    if (!node->child.contains(c)) {
      node->child.insert(make_pair(c, new Node()));
    }
    _insert(node->child[c], s, idx+1);
  }
  void insert(string s) { _insert(root, s, 0); }

  bool _word_exists(Node* node, const string& s, int idx) {
    if (idx == s.size()) return node->leaf;
    const char c = s[idx];
    if (!node->child.contains(c)) return false;
    return _word_exists(node->child[c], s, idx+1);
  }
  bool word_exists(string s) { return _word_exists(root, s, 0); }

  bool _prefix_exists(Node* node, const string& s, int idx) {
    if (idx == s.size()) return true;
    const char c = s[idx];
    if (!node->child.contains(c)) return false;
    return _prefix_exists(node->child[c], s, idx+1);
  }
  bool prefix_exists(string s) { return _prefix_exists(root, s, 0); }
};



#include "test/01.h"
int main() { run_tests(); return 0; }