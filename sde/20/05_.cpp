#include <climits>
using namespace std;

class Solution {
 public:
  bool validate(TreeNode* node, long LL, long RL) {
    if (node==nullptr) return true;
    if (node->val < LL || node->val > RL) return false; // invalid: out of bounds

    return validate(node->left, LL, node->val-1L)
           && validate(node->right, node->val+1L, RL);
  }

  bool isValidBST(TreeNode* root) {
    return validate(root, INT_MIN, INT_MAX);
  }
};