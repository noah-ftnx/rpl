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
class SolutionLTCD {
public:
 vector<vector<int>> levelOrder(TreeNode* root) {
   if (root==nullptr) return {};
   vector<vector<int>> res;

   queue<TreeNode*> q;
   q.push(root);
   while(!q.empty()) {
     int sz=q.size();
     vector<int> level;
     while(sz--) {
       auto node = q.front(); q.pop();
       level.push_back(node->val);

       if(node->left) q.push(node->left);
       if(node->right) q.push(node->right);
     }
     res.push_back(level);
   }

   return res;
 }
};
