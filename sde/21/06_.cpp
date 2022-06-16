class BSTIteratorBF {

 int i=-1;
 vector<int> inorder;

 void dfs(TreeNode* root) {
   if (root==nullptr) return;

   dfs(root->left);
   inorder.push_back(root->val); // VISIT
   dfs(root->right);
 }

public:
 BSTIterator(TreeNode* root) {
   dfs(root); // fill the inorder (in O(N) time and space)
 }

 int next() {
   if (i==inorder.size()) return INT_MIN;
   return inorder[++i];
 }

 bool hasNext() {
   // must not be the last element
   return i<inorder.size()-1;
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
class BSTIterator {
  int curVal;
  TreeNode* root;
 public:
  BSTIterator(TreeNode* root) {
    this->root=root;
    curVal=INT_MIN;
    // apply threading to the tree:
    // visit the whole tree and creating threading:
    // if thread exists: leave it and go right
    // else create it
    // each time going to left, create a thread

    // IF i'm NOT allowed to modify the tree
    // still create threading: but push those threads in an array
    // utilize them with the same order
    // ALGO: recursive:
    // do inorder: vLVR
    // v: will be: before going left: append to vector of threads (separate method)
    // V: actually nothing from this one..

    // THEN: init:
    // place pointer to the leftmost item
    // and then can iterate as normal:
    // if we run out of left pointers: put out of the vector and continue..

    // when it has right:
    // we find the min: go leftmost. each time??

    // HOW ABOUT LOOPS THOUGH?
    // - have a map: when we push something out of the vector: we push it on the map
    // so we dont visit again left!

    // has next?
  }

  int next() {

  }

  bool hasNext() {
    return root && root->right;
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */