#include <unordered_map>
#include <string>
using namespace std;

struct Node {
  unordered_map<char, Node*> child;
  bool leaf;

  bool has(char c) { return child.contains(c); }
  void put (char c) { child.insert(make_pair(c, new Node())); }
  Node* get(char c) { return has(c)?child[c]:nullptr; }
};

struct Trie {
  Node* root = new Node();

  void insert(string s) {
    auto node = root;
    for (auto c: s) {
      if (!node->has(c)) { node->put(c); }
      node=node->get(c);
    }
    node->leaf=true;
  }

  string minimal_prefix(string s) {
   auto node = root;
   for (int i=0; i<s.size(); i++) {
     char c = s[i];
     if (!node->has(c)) return s;
     if (node->leaf) return s.substr(0, i+1); // found
     node=node->get(c);
   }
   return s; // exists, but not a word
  }
};



#include "test/05.h"
int main() { run_tests(); return 0; }
