class SolutionBF {
public:
 TreeNode* insertNode(TreeNode* node, int val) {
   if (node==nullptr) return new TreeNode(val); // insertion point found

   // find insertion point
   if (val < node-> val) node->left=insertNode(node->left, val);
   else node->right=insertNode(node->right, val);

   return node;
 }

 TreeNode* bstFromPreorder(vector<int>& preorder) {
   if (preorder.empty()) return nullptr;

   TreeNode* root = new TreeNode(preorder[0]);

   for (int i=1; i<preorder.size(); i++)
     insertNode(root, preorder[i]);

   return root;
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
#include <climits>
#include <vector>
using namespace std;

class SolutionLimits {
public:
 TreeNode* build(vector<int>& preorder, int &i, int LL, int RL) {
   const int N = (int) preorder.size();
   if (i==N) return nullptr;

   bool inBounds = preorder[i]>=LL && preorder[i]<=RL;
   if (!inBounds) return nullptr;

   auto node = new TreeNode(preorder[i++]);
   node->left=build(preorder, i, LL, node->val-1);
   node->right=build(preorder, i, node->val+1, RL);

   return node;
 }

 TreeNode* bstFromPreorder(vector<int>& preorder) {
   int i=0;
   return build(preorder, i, INT_MIN, INT_MAX);
 }
};


#include <climits>
#include <vector>
using namespace std;

class SolutionLimitsSleek {
 public:
  TreeNode* build(vector<int>& preorder, int &i, int upperBound) {
    if (i >= (int) preorder.size()) return nullptr;
    if (preorder[i] > upperBound) return nullptr;

    // within bounds
    auto node = new TreeNode(preorder[i++]);
    node->left=build(preorder, i, node->val);   // impose a stricter upper bound
    node->right=build(preorder, i, upperBound); // parent's upper bound still applies

    return node;
  }

  TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i=0;
    return build(preorder, i, INT_MAX);
  }
};