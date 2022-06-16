class Solution { // G4G
 private:
  // DFS: RVL
  bool solve(Node* root, int &res, int &k) {
    if (root==nullptr) return false; // base case

    if (solve(root->right, res, k)) return true;

    // VISIT
    if (--k==0) { // found kth largest num
      res=root->data;
      return true;
    }

    return solve(root->left, res, k);
  }

 public:
  int kthLargest(Node *root, int K)
  {
    int res=-1;
    solve(root, res, K);
    return res;
  }
};

// return the Kth largest element in the given BST rooted at 'root'
class SolutionBetterSpace {
 private:

  /*
      when we try to go right we need a way to go back,
      or figure out if we just came from right
  */
  Node* toggleThreading(Node* top) {
    auto node=top->right;
    while(node->left && node->left!=top) node=node->left;

    if (node->left==top) {
      // unset thread and indicate to go left
      node->left=nullptr;
      return nullptr;
    } else {
      // setup thread and return the right node (next direction)
      node->left=top;
      return top->right;
    }
  }

 public:
  int kthLargest(Node *root, int K) {
    int res=-1;
    while(root) {
      if (root->right) {
        auto rightNode = toggleThreading(root);
        if (rightNode) {
          root=rightNode;
        } else {
          // VISIT
          if (--K==0) { res=root->data; }
          root=root->left; // continue left
        }
      } else {
        // VISIT
        if (--K==0) { res=root->data; }
        root=root->left; // continue left
      }
    }
    return res;
  }
};