#include <unordered_map>
#include <string>
using namespace std;

struct Node {
  unordered_map<char, Node*> child;
  bool leaf {};
};

struct Trie {
  Node* root = new Node();

  void insert(string s) {
    auto node = root;
    for (auto c: s) {
       if (!node->child.contains(c)) {
      node->child.insert(make_pair(c, new Node()));
     }
     node=node->child[c];
    }
    node->leaf = true;
  }

  bool word_exists(string s) {
    auto node = root;
    for (auto c: s) {
      if (!node->child.contains(c)) return false;
      node=node->child[c];
    }
    return node->leaf;
  }

  bool prefix_exists(string s) {
    auto node = root;
    for (auto c: s) {
      if (!node->child.contains(c)) return false;
      node=node->child[c];
    }
    return true;
  }

};



#include "test/01.h"
int main() { run_tests(); return 0; }