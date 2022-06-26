#include <unordered_map>
#include <string>
using namespace std;

struct Node {
  unordered_map<char, Node*> child;
  bool leaf=false;

  void put(char c) { child[c]=new Node(); }

  bool has(char c) { return child.count(c)>0; }

  Node* get(char c) {
    if (!has(c)) return nullptr;
    return child[c];
  }
};


class Trie {
  Node *root{};

 public:
  Trie() {
    root=new Node();
  }

  void insert(string word) {
    auto node=root;
    for (char c: word) {
      // h
      // hello
      // add word
      if(!node->has(c)) node->put(c);
      node=node->get(c);
    }
    node->leaf=true;
  }

  bool search(string word) {
    auto node=root;
    for (char c: word) {
      if (!node->has(c)) return false;
      node=node->get(c);
    }
    return node->leaf;
  }

  bool startsWith(string prefix) {
    auto node=root;
    for (char c: prefix) {
      if (!node->has(c)) return false;
      node=node->get(c);
    }
    return true;
  }
};