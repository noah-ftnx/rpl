int findCeil(BinaryTreeNode<int> *node, int x) {
  int ceil = -1;

  while(node) {
    if (x==node->data) return x;
    else if (x > node->data) {
      node=node->right;
    } else {
      ceil=node->data;
      node=node->left;
    }
  }
  return ceil;
}