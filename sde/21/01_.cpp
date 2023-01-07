int floorInBST(TreeNode<int> * root, int X)
{
    int candidate=INT_MAX;
    while (root != nullptr) {
        if (root->val == X) {
            return X; // found exact value
        } else if (X > root-> val) {
            // key is greater than root
            // as root is smaller, it is a candidate
            candidate=root->val;
            root=root->right;
        } else {
            // key is smaller than root
            root=root->left;
        }
    }
    
    return candidate;
}