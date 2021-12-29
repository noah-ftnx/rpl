
#include <unordered_map>
#include <string>
using namespace std;

struct Node {
  unordered_map<char, Node*> child;
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
      if(!node->has(c)) node->put(c);
      node=node->get(c);
    }
    node->leaf=true;
  }

  bool _exists_with_mutations(Node* node, const string& word, int mutations, int idx) {
    if (idx==word.size()) return node->leaf; // TRICKY .size not size-1

    for (auto path: node->child) {
      bool result = false;
      auto child = path.second;
      if (path.first == word[idx]) {
        result = _exists_with_mutations(child, word, mutations, idx+1);
      } else if (mutations > 0){ // mutation
        // mutation: different character
        result = _exists_with_mutations(child, word, mutations-1, idx+1);
        // mutation: empty character
        if (!result) {
          result = _exists_with_mutations(child, word, mutations-1, idx);
        }
      }
      if (result) return true;
    }

    return false;
  }

  bool exists_with_mutations(string& word, int mutations) {
    return _exists_with_mutations(root, word, mutations, 0);
  }

};



#include "test/10.h"
int main() { run_tests(); return 0; }