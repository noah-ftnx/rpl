#include <utility>
using namespace std;

struct Node {
  int value;
  Node* left;
  Node* right;
  Node(int v) : value{v} {}
};

pair<int, bool> recv(Node* node) {
  if (node==nullptr) return {0, true};

  const bool hasLeft = node->left != nullptr;
  const bool hasRight = node->right != nullptr;

  pair<int, bool> leftSide {0, false};
  pair<int, bool> rightSide {0, false};
  bool matches = true; // assume matches w/ cur node
  if (hasLeft) { // eg found 2 in left side...
    leftSide = recv(node->left);
    matches = leftSide.second && node->value==node->left->value;
  }
  if (hasRight) { // eg found 2 in left side...
    rightSide = recv(node->right);
    // TRICKY: take into account whether left side does not match already
    matches = matches && rightSide.second && node->value==node->right->value;
  }

  // handles also leaf cases: (0 + 0 + 1, true)
  return {leftSide.first + rightSide.first + (int) matches, matches};
}

int count_unival(Node* node) {
  auto res = recv(node);
  return res.first;
}



#include "test/008.h"
int main() { run_tests(); }




// ALT, more complex
int complex_count_unival(Node* node) {
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