#include <string>
using namespace std;

struct Node {
  static const int SZ = 26;
  Node* child[SZ] {};
  bool leaf {};

  static int idx(char c) { return c - 'a'; }
};

struct Trie {
  Node* root = new Node();

  void insert(string s) {
    auto node = root;
    for (auto c: s) {
      int idx = Node::idx(c);
      if (!node->child[idx]) { node->child[idx]=new Node(); }
      node=node->child[idx];
    }
    node->leaf = true;
  }

  bool prefix_exists(string s) {
    auto node = root;
    for (auto c: s) {
     int idx = Node::idx(c);
     if (!node->child[idx]) return false;
     node=node->child[idx];
    }
    return true;
  }

  bool word_exists(string s) {
    auto node = root;
    for (auto c: s) {
      int idx = Node::idx(c);
      if (!node->child[idx]) return false;
      node=node->child[idx];
    }
    return node->leaf;
  }
};



#include "test/01.h"
int main() { run_tests(); return 0; }