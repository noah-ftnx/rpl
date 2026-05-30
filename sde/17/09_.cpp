#include <stack>
#include <vector>
using namespace std;

template <class T>
class BinaryTreeNode;

#define PREORDER 1
#define INORDER 0
#define POSTORDER 2

vector<vector<int>> getTreeTraversalRECV(BinaryTreeNode<int> *root);
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root);

#include "test/09.h"

void traverseTree(BinaryTreeNode<int> *node,
                  vector<vector<int>> &traversals) {
  if (node==nullptr) return;
  traversals[PREORDER].push_back(node->data);
  traverseTree(node->left, traversals);
  traversals[INORDER].push_back(node->data);
  traverseTree(node->right, traversals);
  traversals[POSTORDER].push_back(node->data);
}

vector<vector<int>> getTreeTraversalRECV(BinaryTreeNode<int> *root){
  vector<vector<int>> res(3, vector<int>());
  traverseTree(root, res);
  return res;
}

#define INORDER    0
#define PREORDER   1
#define POSTORDER  2

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
  vector<vector<int>> res(3, vector<int>());
  if (root==nullptr) return res;
  struct Item { BinaryTreeNode<int> *node; int id; };
  stack<Item> st;
  st.push({root, 1});
  while(!st.empty()) {
    auto &item = st.top();
    switch(item.id) {
      case 1:
        res[PREORDER].push_back(item.node->data);
        item.id++;
        if (item.node->left) st.push({item.node->left, 1});
        break;
      case 2:
        res[INORDER].push_back(item.node->data);
        item.id++;
        if (item.node->right) st.push({item.node->right, 1});
        break;
      case 3:
        res[POSTORDER].push_back(item.node->data);
        st.pop();
        break;
    }
  }
  return res;
}

int main() { run_tests(); return 0; }
