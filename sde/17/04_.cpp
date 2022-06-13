class SolutionMorris {
public:

 TreeNode* getRightmostNode(TreeNode* top) {
   auto node=top->left;

   // until the node is not the top
   // (a thread we previously setup)
   // or we are at the rightmost node (next is null)
   while (node->right && node->right!=top) node=node->right;

   if (node->right == nullptr) { // must setup thread
     node->right=top; // linking back to top
     return top->left; // return the next direction to follow
   } else { // must cancel thread (already visited left subtree)
     node->right=nullptr;
     return nullptr; // indication to print and move to right
   }
 }

 vector<int> inorderTraversal(TreeNode* root) {
   vector<int> traversal;
   auto node = root;

   while (node) {
     if (node->left==nullptr) {
       // visit and go right
       traversal.push_back(node->val);
       node=node->right; // this might be taking a thread..
     } else {
       // must visit left nodes
       // and create/destroy threads, and move accordingly
       auto leftNode = getRightmostNode(node);
       if (leftNode) { // must go to left
         node=leftNode;
       } else { // coming back from left (and cancelled thread)
         // visit and go right
         traversal.push_back(node->val);
         node=node->right;
       }
     }
   }
   return traversal;
 }
};