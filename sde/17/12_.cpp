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
class Solution {
public:
 int widthOfBinaryTree(TreeNode* root) {
   if (root == nullptr) return 0;

   struct Item { TreeNode* node; int idx; };
   int mx=1;
   queue<Item> q;
   q.push({root, 0});
   while (!q.empty()) {
     // to protect from overflow: instead of continuous numbering
     // we can reset it on each level:
     // e.g. instead of: 4, 5, 6, 7 (on 3-level complete tree),
     // we could have: 1, 2, 3, 4 (on the 3rd level)
     int mnIdx = q.front().idx;
     int lvlItems=q.size();
     int firstIdx, lastIdx;
     for (int i=0; i<lvlItems; i++) {
       auto item = q.front(); q.pop();
       int adjustedIdx = item.idx-mnIdx;
       // covers case of 1 item (root)
       if (i==0) firstIdx=adjustedIdx;
       if (i==lvlItems-1) lastIdx=adjustedIdx; // this must be if to cover root case (not elif)

       int childIdx = (int) (2L*(long)adjustedIdx);
       if (item.node->left) q.push({item.node->left, childIdx+1});
       if (item.node->right) q.push({item.node->right, childIdx+2});
     }
     int width =lastIdx-firstIdx+1;
     mx=max(mx, width);
   }
   return mx;
 }
};
