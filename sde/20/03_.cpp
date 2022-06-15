class Solution {
 public:

  TreeNode* buildBST(vector<int>& nums, int l, int r) {
    if (r<l) return nullptr;

    // int mid = (l+r)/2; // overflow safe:
    int sz = r-l;
    int mid = l+(sz/2);

    auto node = new TreeNode(nums[mid]);

    node->left=buildBST(nums, l, mid-1);
    node->right=buildBST(nums, mid+1, r);

    return node;
  }

  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return buildBST(nums, 0, nums.size()-1);
  }
};