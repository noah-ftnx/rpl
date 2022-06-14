/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

bool fillPath(TreeNode *node, int query, vector<int> &path) {
 if (node==nullptr) return false; // base case: dead end

 path.push_back(node->val);
 if (node->val == query) return true; // base case: found

 if (fillPath(node->left, query, path)) return true;
 if (fillPath(node->right, query, path)) return true;

 path.pop_back();

 return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
 vector<int> res;
 fillPath(A, B, res);
 return res;
}

