#include <string>
using namespace std;

struct Node {
  char data;

  Node* left {};
  Node* right {};
  Node* equal {};
  bool word {};

  Node(char c) : data{c} {}
};


struct TST {
  Node* root {};

  void _insert(const string& s, int idx, Node*& node) {
    const char c = s[idx];
    if (node == nullptr) { node = new Node(c); }

    if (c < node->data) {
      _insert(s, idx, node->left);
    } else if (c > node->data) {
      _insert(s, idx, node->right);
    } else {
      if (idx==s.size()-1) { // mark last letter as word
        node->word=true;
      } else { // consume input and continue
       _insert(s, idx+1, node->equal);
      }
    }
  }

  void insert(const string& s) { _insert(s, 0, root); }

  bool find(const string& s, int idx, Node* node) {
    if (node == nullptr || s.empty()) return false;
    const char c = s[idx];
    if (c < node->data) {
      return find(s, idx, node->left);
    } else if  (c > node->data) {
      return find(s, idx, node->right);
    } else {
      if (idx==s.size()-1) return node->word;
      else return find(s, idx+1, node->equal); // consume & continue
    }
  }
  bool find(const string& s) { return find(s, 0, root); }

  void _remove(const string& s, int idx, Node*& node) {
    if (node == nullptr || s.empty()) return;
    const char c = s[idx];

    if (c < node->data) {
      _remove(s, idx, node->left);
    } else if (c > node->data) {
      _remove(s, idx, node->right);
    } else {
      if (idx == s.size()-1) {
        node->word=false;
      } else { // consume & continue
        _remove(s, idx+1, node->equal);
      }
    }
  }
  void remove(const string & s) { _remove(s, 0, root); }
};



#include "test/11.h"
int main() { run_tests(); return 0; }