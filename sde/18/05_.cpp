/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution1 {
public:

 struct Item {
   TreeNode* lca {};
   bool p;
   bool q;
 };

 Item dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
   Item res {nullptr, false, false};
   if (node==nullptr) return res;

   auto left = dfs(node->left, p, q);
   if (left.lca) return left;            // previously found lca
   auto right = dfs(node->right, p, q);
   if (right.lca) return right;          // previously found lca

   // figure out if p or q are found:
   // found on left or right or cur node
   res.p=left.p||right.p||node==p;
   res.q=left.q||right.q||node==q;

   // both pq found:  cur node is lca
   if (res.p && res.q) res.lca=node;

   return res;
 }

 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
   auto res = dfs(root, p, q);
   return res.lca;
 }
};


class SolutionSimplified {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;
    else if(root==p || root==q) return root; // found one of the 2

    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);

    // if lca was found: what happens on backtracked calls?
    // - lca can be on either left or right
    // - but one of them has to be null (as both p, q were found)


    if (left==nullptr) {  // might be searching for p or q or both
      // if lca was on the right: will still be returned!
      return right; // when null: OK. still searching for both.
    } else if (right==nullptr) { // same with above
      return left;
    } else { // both were found. LCA was found
      return root;
    }
  }
};