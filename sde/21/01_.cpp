int floorInBST(TreeNode<int> * root, int X) {
  int res=-1;
  while (root) {
    if (root->val == X) return X;
    else if (X > root-> val) {
      res=root->val;
      root=root->right;
    } else {
      root=root->left;
    }
  }
  return res;
}