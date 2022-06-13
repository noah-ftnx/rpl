#include <vector>
using namespace std;

class SolutionRecursive {
public:
 void preorder(TreeNode* node, vector<int> &traversal) {
   if (node==nullptr) return; // base case

   traversal.push_back(node->val);
   preorder(node->left, traversal);
   preorder(node->right, traversal);

 }
 vector<int> preorderTraversal(TreeNode* root) {
   vector<int> traversal;
   preorder(root, traversal);
   return traversal;
 }
};


#include <stack>
#include <vector>
using namespace std;

class SolutionIterative {
 public:

  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> traversal;
    stack<TreeNode*> st;
    auto node = root;
    while(true) {
      if (node != nullptr) {
        // visit and try to go left
        traversal.push_back(node->val);
        st.push(node);
        node=node->left;
      } else { // have to pop and continue
        if (st.empty()) break; // traversal done

        node=st.top(); st.pop();
        node=node->right;
      }
    }

    return traversal;
  }
};


class SolutionIterativeSimpler {
 public:

  vector<int> preorderTraversal(TreeNode* root) {
    if (root==nullptr) return {};

    vector<int> traversal;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
      auto node = st.top(); st.pop();
      traversal.push_back(node->val);

      // push first right, then left (we use LIFO)
      if (node->right) st.push(node->right);
      if (node->left) st.push(node->left);
    }

    return traversal;
  }
};