#include <unordered_map>
#include <vector>
#include <vector>
#include <string>
using namespace std;


struct Node {
  unordered_map<char, Node*> child {};

  bool leaf {};
  bool has(char c) { return child.contains(c); }
  void put(char c) { child.insert(make_pair(c, new Node())); }
  Node* get(char c) { return has(c)?child[c]:nullptr; }
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

  void _fill_results(Node* node, string prefix, vector<string>& result) {
    if (node->leaf) result.push_back(prefix);  // continue: might have other children

    for (auto pair: node->child) {
      _fill_results(pair.second, prefix+pair.first, result);
    }
  }

  void autocomplete(string prefix, vector<string>& result) {
    // navigate to the subtrie
    auto node = root;
    for (auto c: prefix) {
      if (!node->has(c)) return;
      node=node->get(c);
    }

    _fill_results(node, prefix, result);
  }

};



#include "test/011.h"
int main() { run_tests(); return 0; }