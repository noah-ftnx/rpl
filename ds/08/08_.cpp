#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <utility>
using namespace std;

struct Node {
  unordered_map<char, Node*> child;
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
};

unordered_set<string> find_substr(Trie& trie, string str) {
  auto node = trie.root;
  unordered_set<string> result;
  for (int i=0; i<str.size(); i++) { // O(SL)
    const char c = str[i];
    if (node->has(c)) { // a substring might start here
      auto node_inner = node;
      for (int j=i; j<str.size(); j++) {
        if (node_inner->leaf) {
          result.insert(str.substr(i, j-i));
        }
        if (!node_inner->has(str[j])) break;
        node_inner=node_inner->get(str[j]);
      }
    }

  }
  return result;
}

unordered_set<string> list_substrs(const string& str, const vector<string>& queries) {
  auto trie = Trie();
  for (auto query: queries) { trie.insert(query); } // O(QL)
  return find_substr(trie, str);
}



#include "test/08.h"
int main() { run_tests(); return 0; }