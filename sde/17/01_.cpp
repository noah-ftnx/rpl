class SolutionRecv {
 public:
  void inorder(TreeNode* node, vector<int>& traversal) {
    if (node == nullptr) return;  // base case

    inorder(node->left, traversal);
    traversal.push_back(node->val);  // visit
    inorder(node->right, traversal);
  }

  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> traversal;

    inorder(root, traversal);
    return traversal;
  }
};


#include <stack>
using namespace std;

class SolutionIterative {
 public:

  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> traversal;

    auto node=root;
    stack<TreeNode*> st;

    while (true) {
      if (node != nullptr) {
        // try to go left
        st.push(node);
        node=node->left; // night be nullsxc
      } else { // node was null
        if (st.empty()) break; // traversal finished
        // else: pop, visit, and try right
        node=st.top(); st.pop();
        traversal.push_back(node->val);

        node=node->right;
      }
    }
    return traversal;
  }
};