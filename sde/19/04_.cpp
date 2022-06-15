class Solution {
public:
 bool symmetricTrees(TreeNode* t1, TreeNode* t2) {
   if (t1 == nullptr && t2 == nullptr) return true; // symmetry
   else if (t1 == nullptr || t2 == nullptr) return false; // no symmetry: just 1 is null


   // value matches and drive then w/ opposite directions
   return (t1->val == t2->val) &&
          symmetricTrees(t1->left, t2->right) &&
          symmetricTrees(t1->right, t2->left);
 }

 bool isSymmetric(TreeNode* root) {
   if (root==nullptr) return true;
   return symmetricTrees(root->left, root->right);
 }
};