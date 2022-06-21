class Solution {
  struct Item {
    int mn, mx, sum;
    bool valid, nil;
  };

  Item solve(TreeNode* node, int &mx) {
    // nulls will messup limits, so dont visit null nodes..
    if (node==nullptr) return {0, 0, 0, true, true};

    auto left=solve(node->left, mx);
    auto right=solve(node->right, mx);

    // VISIT:
    Item cur;
    cur.nil=false;

    // find subtree validity:
    cur.valid=left.valid && right.valid; // at least both must be valid
    // then further check some limits:
    if (cur.valid && !left.nil) { cur.valid = node->val > left.mx; }
    if (cur.valid && !right.nil) { cur.valid = node->val < right.mn; }

    if (!cur.valid) return cur; // dummy values, but no need to further check anything

    // validity passed:
    // no mn, mx levels on side that has no child
    cur.mn=left.nil? node->val : left.mn;
    cur.mx=right.nil? node->val : right.mx;

    cur.sum=left.sum+right.sum+node->val;
    mx=max(mx, cur.sum);

    return cur;
  }

 public:
  int maxSumBST(TreeNode* root) {
    // if all negatives? can take empty subtree (so max is 0)
    int res=0;
    solve(root, res);
    return res;
  }
};