
// GFG: Function to convert a binary tree into its mirror tree.
void mirror(Node* node) {
  if (node==nullptr) return; // base case

  // if one is null: still OK. we want to swap

  mirror(node->left);
  mirror(node->right);

  swap(node->left, node->right);
}