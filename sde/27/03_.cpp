#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#ifdef _SLOWER_

struct Node {
  unordered_map<char, Node*> child;
  void put(char c) { child[c]=new Node(); }
  bool has(char c) { return child.count(c) > 0; }
  Node* get(char c) { return has(c)? child[c] : nullptr; }

  bool word=false;
};

class Trie {
  Node* root;
  string solution;

 public:
  Trie() {
    root = new Node();
  }

  string getSolution() {
    return solution.empty()? "None" : solution;
  }

  void insert(string s) {
    const int S = (int) s.size();
    Node* node = root;
    for (int i=0; i<S; i++) {
      const char c = s[i];
      if (!node->has(c)) {
        // S: 5
        // 01234
        // nin
        // ninga
        //
        // since it's sorted: each new node must only be
        // the last one
        // e.g.:
        // a OK
        // ab OK
        // abbbbb: NO NEED to check on that.. (and to add...)
        if (i < S-1) return;

        node->put(c);
      }
      node=node->get(c);
    }

    if (S > (int) solution.size()) solution=s;
  }

};

string completeStringSlower(int n, vector<string> &a){
  Trie trie;
  for (string word: a) trie.insert(word);

  return trie.getSolution();
}
#endif






#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
  unordered_map<char, Node*> child;
  void put(char c) { child[c]=new Node(); }
  bool has(char c) { return child.count(c) > 0; }
  Node* get(char c) { return has(c)? child[c] : nullptr; }

  bool word=false;
};

class Trie {
  Node* root;

  void dfs(Node* node, string s, string &solution) {
    if (s.size() > solution.size()) solution = s;
    else if (s.size() == solution.size()) {
      // add only if lexig. first
      if (s < solution) solution = s;
    }

    for (auto child: node->child) {
      char c = child.first;
      Node *next = child.second;
      if (next->word) {
        dfs(next, s+c, solution);
      }
    }
  }

 public:
  Trie() {
    root = new Node();
  }

  string getSolution() {
    string solution;
    dfs(root, "", solution);
    return solution.empty()? "None" : solution;
  }

  void insert(string s) {
    const int S = (int) s.size();
    Node* node = root;
    for (int i=0; i<S; i++) {
      const char c = s[i];
      if (!node->has(c)) node->put(c);
      node=node->get(c);
    }
    node->word=true;
  }
};

string completeString(int n, vector<string> &a){
  Trie trie;
  for (string word: a) trie.insert(word);

  return trie.getSolution();
}