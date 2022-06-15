class Solution {
 public:
  TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &i, int l, int r) {
    const int N = preorder.size();
    if (i==N) return nullptr;
    if (r < l) return nullptr;

    auto node = new TreeNode(preorder[i]);
    i++;

    if (l==r) return node; // leaf node

    // find k: position in inorder
    int k;
    for (k=0; k<N; k++) if (inorder[k]==node->val) break;

    node->left = build(preorder, inorder, i, l, k-1);
    node->right = build(preorder, inorder, i, k+1, r);

    return node;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int idx=0;
    return build(preorder, inorder, idx, 0, preorder.size()-1);
  }
};


#include <unordered_map>
#include <vector>
using namespace std;

class SolutionOPT {
 public:
  TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &i,
                  int l, int r, unordered_map<int, int> &mp) {
    const int N = preorder.size();
    if (i==N) return nullptr;
    if (r < l) return nullptr;

    auto node = new TreeNode(preorder[i]);
    i++;

    if (l==r) return node; // leaf node

    int k = mp[node->val]; // find k: position in inorder

    node->left = build(preorder, inorder, i, l, k-1, mp);
    node->right = build(preorder, inorder, i, k+1, r, mp);

    return node;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int idx=0;

    unordered_map<int, int> mp;
    for (int i=0; i<inorder.size(); i++) {
      mp[inorder[i]]=i; // value '4' is at idx '0'
    }

    return build(preorder, inorder, idx, 0, preorder.size()-1, mp);
  }
};