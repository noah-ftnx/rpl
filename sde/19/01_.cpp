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
class SolutionCOMPLEX {
 public:
  int findMax(TreeNode* node, int &mxSum) {
    if (node == nullptr) return 0;

    int leftSum = findMax(node->left, mxSum);
    int rightSum = findMax(node->right, mxSum);

    // cant have empty result: e.g. if root is negative, result must be negative

    // UPDATE mxSum:
    // edge case: just cur node: cur node by itself is max
    mxSum=max(mxSum, node->val);

    // 1. considering only left/right sides (given non null)
    // excluding cur node (as it might be negative)
    if (leftSum!=0) mxSum=max(mxSum, leftSum);
    if (rightSum!=0) mxSum=max(mxSum, rightSum);

    // 2. including node (as it might not be negative)
    mxSum=max(mxSum, leftSum+node->val);
    mxSum=max(mxSum, rightSum+node->val);

    // 3. including all (as we might have no negatives)
    // if node->val is negative: still has to be included to form a path
    mxSum=max(mxSum, leftSum+rightSum+node->val);

    // return a valid path:
    // 1. including ourself only (node), or ourself plus the max of the child paths
    // (covering edge case: both child are negatives, so we can start a new path)
    int maxChildPath=max(leftSum, rightSum);
    return max(node->val, node->val+maxChildPath);
  }

  int maxPathSum(TreeNode* root) {
    if (root==nullptr) return 0;

    int mxSum=INT_MIN;
    findMax(root, mxSum);
    return mxSum;
  }
};


class SolutionSleek {
 public:

  int findMaxPath(TreeNode* node, int &mx) {
    if (node==nullptr) return 0;

    // get left and right paths
    // if any path is negative: cut it off
    int leftPath=max(0, findMaxPath(node->left, mx));
    int rightPath= max(0, findMaxPath(node->right, mx));

    // update max
    mx=max(mx, leftPath+rightPath+node->val);

    // return: a valid path that includes cur node
    return node->val + max(leftPath, rightPath);
  }

  int maxPathSum(TreeNode* root) {
    int maxPath=INT_MIN;
    findMaxPath(root, maxPath);
    return maxPath;
  }
};