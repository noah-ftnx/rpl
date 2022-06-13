class SolutionMorris {
 public:
  TreeNode* getRightmostNode(TreeNode* top) {
    auto node = top->left;
    while (node->right && node->right!=top) node=node->right;
    if (node->right == nullptr) {
      // create a thread and return the left node
      node->right=top;
      return top->left;
    } else {
      // unset the thread, and return NULL
      node->right=nullptr;
      return nullptr;
    }
  }

  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> traversal;
    auto node = root;
    while (node) {

      if (node->left) {  // create or cancel thread, and pick direction accordingly
        auto leftNode = getRightmostNode(node);
        if (leftNode) { // visit left subtree
          // but before, we must print in preorder traversal
          traversal.push_back(node->val);
          node=leftNode;
        }
        else { // visit right subtree
          node=node->right;
        }

      } else { // visit right subtree
        // in preorder we print here
        traversal.push_back(node->val);
        node=node->right;
      }
    }
    return traversal;
  }
};