class Solution {
 public:
  TreeNode* searchBST(TreeNode* root, int val) {
    if (root==nullptr) return nullptr;

    if (root->val == val) return root;
    else if (val < root->val) return searchBST(root->left, val);
    else return searchBST(root->right, val);
  }
};

class SolutionIterative {
 public:
  TreeNode* searchBST(TreeNode* root, int val) {
    while (root && root->val != val) {
      if (val < root->val) root=root->left;
      else root=root->right;
    }
    return root;
  }
};