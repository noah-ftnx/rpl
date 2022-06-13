class SolutionRecursive {
public:
 void postorder(TreeNode* node, vector<int> &traversal) {
   if (node==nullptr) return; // base case

   postorder(node->left, traversal);
   postorder(node->right, traversal);

   traversal.push_back(node->val);
 }
 vector<int> postorderTraversal(TreeNode* root) {
   vector<int> traversal;
   postorder(root, traversal);
   return traversal;
 }
};


#include <stack>
using namespace std;

class SolutionIterative {
 public:

  vector<int> postorderTraversal(TreeNode* root) {
    if (root == nullptr) return {};
    vector<int> traversal;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
      auto node = st.top(); st.pop();
      traversal.push_back(node->val);
      if (node->left) st.push(node->left);
      if (node->right) st.push(node->right);
    }

    reverse(traversal.begin(), traversal.end());
    return traversal;
  }
};