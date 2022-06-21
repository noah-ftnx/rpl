#include <stack>
using namespace std;

class Solution {
 private:
  stack<TreeNode*> small, big;

  void fillSmall(TreeNode* node) {
    while(node) {
      small.push(node);
      node=node->left;
    }
  }

  void fillBig(TreeNode* node) {
    while(node) {
      big.push(node);
      node=node->right;
    }
  }

  int peakTops() {
    return big.top()->val + small.top()->val;
  }

  void popSmall() {
    auto node = small.top(); small.pop();
    if (node->right) fillSmall(node->right);
  }

  void popBig() {
    auto node = big.top(); big.pop();
    if (node->left) fillBig(node->left);
  }

 public:
  bool findTarget(TreeNode* root, int k) {
    if (root == nullptr) return false;

    fillSmall(root);
    fillBig(root);

    while(!small.empty() && !big.empty()) {
      int val = peakTops();
      if (val==k) { // may be as olution:
        if (small.top()==big.top()) {
          popSmall(); // pop one of those.. we need 2 DIFF nodes
        } else return true;
      } else if (val > k) { // need a smaller num
        popBig();
      } else { // need a bigger num
        popSmall();
      }
    }
    return false;
  }
};