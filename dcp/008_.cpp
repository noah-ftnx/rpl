#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* left;
  Node* right;
  Node(int v) : value{v} {}
};

int count_unival(Node* node) {
  if (node == nullptr) return 0;
  if (!node->left && !node->right) return 1; // leaf

  int res = 0;
  bool L = node->left != nullptr;
  bool R = node->right!= nullptr;
  bool matchL;
  bool matchR;
  if (L) {
    res+=count_unival(node->left);
    matchL = node->value == node->left->value;
  }
  if (R) {
    res+=count_unival(node->right);
    matchR = node->value == node->right->value;
  }

  if (L) {
    if (matchL) { // matches
      if (R && matchR) res++; // both match
      else if (!R) res++; // only L and matches
    }
  } else if (R && matchR) {
    res++; // only R and matches
  }

  return res;
}

#include "test/008.h"

int main() { run_tests(); }