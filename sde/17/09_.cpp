#include <vector>
using namespace std;

#define PREORDER 1
#define INORDER 0
#define POSTORDER 2

void traverseTree(BinaryTreeNode<int> *node,
                  vector<vector<int>> &traversals) {
  if (node==nullptr) return;

  traversals[PREORDER].push_back(node->data);

  traverseTree(node->left, traversals); // GO LEFT
  traversals[INORDER].push_back(node->data);

  traverseTree(node->right, traversals);  // GO RIGHT
  traversals[POSTORDER].push_back(node->data);
}

vector<vector<int>> getTreeTraversalRECV(BinaryTreeNode<int> *root){
  vector<vector<int>> res(3, vector<int>());
  traverseTree(root, res);

  return res;
}






/*

use a stack, and an id:
- we'll push root to stack with id 1 (first time) means go to preorde

- id 0: item was just pushed, so put in preorder
- id : item was pushed twice in stack, so put in inorder
- id 3: 3 times, so post order

init stack with root and 1

while not empty:
  - peak top id: according to id, put in relevan stack
  - if id 2: remove altogether from stack

  - if has right: push it with id1
  - if has left: push it with id1
*/

#include <vector>
#include <stack>
using namespace std;

#define INORDER    0
#define PREORDER   1
#define POSTORDER  2

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
  vector<vector<int>> res(3, vector<int>());
  if (root==nullptr) return res;
  struct Item { BinaryTreeNode<int> *node; int id; };
  stack<Item> st;
  st.push({root, 1});

  while(!st.empty()) { // add to relevant traversal
    auto &item = st.top();
    switch(item.id) {
      case 1:
        res[PREORDER].push_back(item.node->data);
        item.id++;
        // add left node
        if (item.node->left) st.push({item.node->left, 1});
        break;
      case 2:
        res[INORDER].push_back(item.node->data);
        item.id++;
        // add right nodev
        // (so this top will be emited afterwards in post order traversal)
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