class Solution {
  bool solve(TreeNode* root, int &k, int &res) {
    if (root==nullptr) return false;

    if (solve(root->left, k, res)) return true;

    // visit:
    if (--k==0) {
      res=root->val;
      return true;
    }

    return solve(root->right, k, res);
  }

 public:
  int kthSmallest(TreeNode* root, int k) {
    int res=-1;
    solve(root, k, res);
    return res;
  }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class SolutionThreading {
  /* when setting up: return the left node to follow
     when unsetting: returning null (go right)
  */
  TreeNode* toggleThread(TreeNode* top) {
    auto node = top->left;
    while(node->right && node->right != top) node=node->right;

    if (node->right == top) { // unset
      node->right=nullptr;
      return nullptr;
    } else { // set
      node->right=top;
      return top->left;
    }
  }

 public:
  int kthSmallest(TreeNode* root, int k) {

    int result=-1;

    while (root) {
      if (root->left) {
        // set/unset threading, decide where to go:
        // if threading exists: (have just returned)
        // - unset it
        // - visit node
        // - and go right
        // if not:
        // set it up
        // - and go left
        auto leftNode = toggleThread(root);
        if (leftNode) {
          root=leftNode;
        } else {
          if (--k==0) result=root->val; // VISIT

          root=root->right;
        }
      } else {
        if (--k==0) result=root->val; // VISIT

        root=root->right;
      }
    }
    return result;
  }
};