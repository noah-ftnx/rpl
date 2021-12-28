#include <unordered_map>
#include <string>
using namespace std;

struct Node {
  unordered_map<char, Node*> child;
  bool dir {};
  bool has(char c) { return child.contains(c); }
  void put(char c) { child.insert(make_pair(c, new Node())); }
  Node* get(char c) { return has(c)?child[c]:nullptr; }
};

struct Trie {
  Node* root = new Node();

  void insert(string path) {
    auto node = root;
    for (int i=0; i<path.size(); i++) {
      const char c = path[i];
      if (c == '/') { // and of dir
        if (i==0) { // to show only paths that start with /
          if (!node->has(c)) node->put(c);
          node=node->get(c);
        }
        node->dir=true;
      } else {
        if (!node->has(c)) node->put(c);
        node=node->get(c);
      }
    }
    node->dir=true;
  }

  bool has_path(string path) {
    auto node = root;
    for (int i=0; i<path.size(); i++) {
      const char c = path[i];
      if (c == '/' && i!=0) {
       if (!node->dir)  return false;
      } else {
        if (!node->has(c)) return false;
        node=node->get(c);
      }
    }
    return node->dir;
  }
};



#include "test/06.h"
int main() { run_tests(); return 0; }
