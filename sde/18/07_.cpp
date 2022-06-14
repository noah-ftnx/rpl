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
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
   vector<vector<int>> res;
   queue<TreeNode*> q;
   if (root != nullptr) q.push(root);

   bool reverse=false;
   while(!q.empty()) {
     const int sz = q.size();
     vector<int> levelNodes(sz);
     for (int i=0; i<sz; i++) {
       auto node = q.front(); q.pop();

       int idx = reverse? sz-i-1 : i;

       levelNodes[idx]=node->val;

       if (node->left) q.push(node->left);
       if (node->right) q.push(node->right);
     }

     res.push_back(levelNodes);
     reverse=!reverse;
   }
   return res;
 }
};
