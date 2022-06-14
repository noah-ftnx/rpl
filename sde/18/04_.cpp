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
#include <utility>
using namespace std;

class Solution {
public:

 int dfs(TreeNode* node) {
   if (node==nullptr) return 0;

   int left = dfs(node->left);
   if (left==-1) return -1; // inbalance

   int right = dfs(node->right);
   if (right==-1) return -1; // inbalance

   bool notBalanced = abs(left-right)>1;
   if (notBalanced) return -1;

   return 1+ max(left, right);
 }

 bool isBalanced(TreeNode* root) {
   return dfs(root)!=-1;
 }
};
