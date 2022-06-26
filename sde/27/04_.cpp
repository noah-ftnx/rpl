#include <string>
using namespace std;

struct Node {
  Node* child[26];
  //   map<char, Node*> child;
  bool word=false;

  void put(char c) { child[c-'a']=new Node(); }
  bool has (char c) { return child[c-'a'] != nullptr ; }
  Node* get(char c) { return child[c-'a']; }
};

struct Trie {
  Node* root;
  int unique_str=0;
  Trie() {
    root = new Node();
  }

  void insert(string s) {
    if (s.empty()) return;
    Node* node=root;
    for (char c: s) {
      if (!node->has(c)) {
        node->put(c);
      }
      node=node->get(c);
    }
    if (!node->word) { // this was a new word
      unique_str++;
      node->word=true;
    } // else: the word existed
       // this also means that no new node was added (in above loop)
  }
};

int countDistinctSubstrings(string &s) {
  Trie t;

  const int S = (int) s.size();
  // genereate all permutations:
  for (int i=0; i<S; i++) {
    for (int j=i; j<S; j++) { // inclusive
      string str = s.substr(i, j-i+1);
      t.insert(str);
    }
  }

  return 1 + t.unique_str;  // +1 for empty string
}