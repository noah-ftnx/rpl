class Solution {
 public:

  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int &i, int l, int r) {
    if (i < 0) return nullptr;
    if (r < l) return nullptr; // invalid range

    auto node = new TreeNode(postorder[i]);
    i--;

    const int N = inorder.size();
    int k;
    for (k=0; k<N; k++) if (inorder[k]==node->val) break;

    node->right=buildTree(inorder, postorder, i, k+1, r);
    node->left= buildTree(inorder, postorder, i, l, k-1);

    return node;
  }

  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    // i: N-1: might start with negaive..
    const int N = inorder.size();
    int i=N-1;
    return buildTree(inorder, postorder, i, 0, N-1);
  }
};


#include <unordered_map>
using namespace std;

class SolutionOPT {
 public:

  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int &i, int l, int r,
                      unordered_map<int, int> &mp) {
    if (i < 0) return nullptr;
    if (r < l) return nullptr; // invalid range

    auto node = new TreeNode(postorder[i]);
    i--;

    const int N = inorder.size();
    int k=mp[node->val];

    node->right=buildTree(inorder, postorder, i, k+1, r, mp);
    node->left= buildTree(inorder, postorder, i, l, k-1, mp);

    return node;
  }

  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    const int N = inorder.size();
    unordered_map<int, int> mp;
    for (int i=0; i<N; i++) {
      mp[inorder[i]]=i; // val 4 -> idx 0
    }

    int i=N-1;  // might start with negaive..
    return buildTree(inorder, postorder, i, 0, N-1, mp);
  }
};