#include <unordered_map>
#include <string>
using namespace std;
struct Node {
  unordered_map<char, Node*> child;
  bool has(char c) { return child.contains(c); }
  void put(char c) { child.insert(make_pair(c, new Node())); }
  Node* get(char c) { return has(c)? child[c]:nullptr; }
};

struct Trie {
  Node* root = new Node();

  void insert(string s) {
    auto node = root;
    for (int i = s.size()-1; i>=0; i--) {
      const char c = s[i];
      if (!node->has(c)) node->put(c);
      node=node->get(c);
    }
  }

  bool suffix_exists(string suffix)  {
    if (suffix.size()==0) return false;
    auto node = root;
    for (int i = suffix.size()-1; i>=0; i--) {
      const char c = suffix[i];
      if (!node->has(c))  return false;
      node=node->get(c);
    }
    return true;
  }
};



#include "test/06.h"
int main() { run_tests(); return 0; }