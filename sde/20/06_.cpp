class Solution {
public:
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
   if (root==nullptr) return nullptr;
   if (root == p || root==q) return root; // found one of them

   TreeNode* node{};
   // both lie on left side
   if (p->val < root->val && q->val < root->val) {
     return lowestCommonAncestor(root->left, p, q);
   } else if (p->val > root->val && q->val > root->val) { // both on right side
     return lowestCommonAncestor(root->right, p, q);
   } else {
     return root;
   }
 }
};


class SolutionIterative {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while(root) {
      if (p->val < root->val && q->val < root->val) {
        root=root->left;
      } else if (p->val > root->val && q->val > root->val) { // both on right side
        root=root->right;
      } else break;
    }
    return root;
  }
};