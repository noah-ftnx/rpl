bool isLeaf(TreeNode<int>* node) {
  return node->left==nullptr && node->right == nullptr;
}

void addLeftBoundary(TreeNode<int>* root, vector<int> &res) {
  // 1. ADD LEFT-SIDE NODES
  // while node exists, and is not leaf,
  // and is not the last left node
  auto node=root->left;
  while (node && !isLeaf(node)) {
    res.push_back(node->data);
    // go as left as possible, otherwise go right
    if (node->left) node=node->left;
    else node=node->right;
  }
}

void addRightBoundary(TreeNode<int>* root, vector<int> &res) {
  vector<int> mustReverse;  // add these in reverse
  auto node=root->right;
  while (node && !isLeaf(node)) {
    mustReverse.push_back(node->data);
    // go as right as possible, otherwise go right
    if(node->right) node=node->right;
    else node=node->left;
  }

  if (!mustReverse.empty()) {
    // add right nodes in reverse
    res.insert(res.end(), mustReverse.rbegin(), mustReverse.rend());
  }
}

void addLeaves(TreeNode<int>* node, vector<int> &res) {
  if (node==nullptr) return;

  addLeaves(node->left, res);
  if (isLeaf(node)) res.push_back(node->data);
  addLeaves(node->right, res);
}

vector<int> traverseBoundary(TreeNode<int>* root){
  if (root == nullptr) return {};  // edge case

  // add root:
  vector<int> res;
  res.push_back(root->data);
  if (isLeaf(root)) return res; // edge case

  addLeftBoundary(root, res);
  addLeaves(root, res);
  addRightBoundary(root, res);
  return res;
}