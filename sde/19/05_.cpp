#include <vector>
using namespace std;

class SolutionIterativeSpace {
public:
 void fillPreorder(TreeNode* node, vector<TreeNode*> &preorder) {
   if (node==nullptr) return;

   // VLR
   preorder.push_back(move(node));
   fillPreorder(node->left, preorder);
   fillPreorder(node->right, preorder);
 }

 void flatten(TreeNode* root) {
   if (root==nullptr) return;
   vector<TreeNode*> preorder;
   fillPreorder(root, preorder);

   const int N = (int) preorder.size();
   // fix tree...
   for (int i=0; i<N; i++) {
     auto node = preorder[i];
     if (i==N-1) {
       node->left=node->right=nullptr;
     } else {
       node->left=nullptr;
       node->right=preorder[i+1];
     }
   }

 }
};

class SolutionIterativeNoSpace {
 public:
  void flatten(TreeNode* root) {
    auto findPredecessor = [](TreeNode* node) -> TreeNode* {
      node=node->left;
      while(node->right) node=node->right;
      return node;
    };

    auto node = root;
    while (node) {

      if (node->left != nullptr) {
        auto predecessor = findPredecessor(node);
        predecessor->right=node->right;
        node->right=node->left;
        node->left=nullptr;
      }
      node=node->right;
    }
  }
};


class SolutionRecursion {
 public:
  void flatten(TreeNode* root) {
    // first pointing to prev will be from the very last node, so OK
    static TreeNode* prev=nullptr;

    if (root==nullptr) return; // base case

    flatten(root->right);
    flatten(root->left);

    // fixup
    root->right=prev;
    root->left=nullptr;
    prev=root;
  }
};