#include <vector>
using namespace std;

struct Node {
  int data {};
  Node* left {};
  Node* right {};

  explicit Node(int data) : data{data} {}
};

class BSTree {
 public:
  Node* root {};

  void insert(int data) {
    if (!root) {
      root = new Node(data);
      return;
    }

    auto node = root;
    while (true) {
      if (data < node->data) {
        if (!node->left) {
          node->left = new Node(data);
          return;
        }
        node = node->left;
      } else {
        if (!node->right) {
          node->right = new Node(data);
          return;
        }
        node = node->right;
      }
    }
  }

  void insert(const vector<int>& values) {
    for (auto value: values) insert(value);
  }
};

#include "test/02-insert-bst.h"
int main() { run_tests(); return 0; }
