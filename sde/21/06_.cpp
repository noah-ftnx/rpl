class BSTIteratorBF {
 int i=-1;
 vector<int> inorder;

 void dfs(TreeNode* root) {
   if (root==nullptr) return;

   dfs(root->left);
   inorder.push_back(root->val); // VISIT
   dfs(root->right);
 }

public:
 BSTIterator(TreeNode* root) {
   // fill the inorder (in O(N) time and space)
   dfs(root);
 }

 int next() {
   if (i==inorder.size()) return INT_MIN;
   return inorder[++i];
 }

 bool hasNext() {
   // must not be the last element
   return i < ((int)inorder.size()-1); // overflow prot
 }
};


#include <queue>
#include <vector>
using namespace std;

class BSTIteratorComplex {
  TreeNode* root;
  TreeNode* it;
  queue<TreeNode*> backlinks;

  bool toggleThreading(TreeNode* top) {
    // set or unset threading
    // when setting:
    // - return the left of top (node to follow next)
    // when usetting:
    // push in backlinks
    // - return null (signal to go right)

    auto node=top->left;

    while(node->right && node->right != top) node=node->right;

    if (node->right == top) { // unset
      backlinks.push(node->right);
      node->right=nullptr;
      return false;
    } else { // set
      node->right=top;
      return true;
    }
  }

  // populate (max H) backlinks
  void generateBacklinks() {
    auto node=root;
    while (node) {
      if (node->left) {
        auto goLeft = toggleThreading(node);
        if (goLeft) {
          node=node->left;
        } else {
          // visit: do noth..
          node=node->right;
        }
      } else {
        // visit: do noth..
        node=node->right;
      }
    }
  }

 public:
  BSTIterator(TreeNode* root) {
    this->root=root;
    generateBacklinks();
    // move to min node
    it = root;
    while (it->left) it=it->left;

    /*
    CTOR:
    do a threaded traversal:
    - on unsetting: push backlinks to a vector
    then:
    - add a ptr to the leftmost node (smallest element)

    - next:
      - check if not null
      - return cur val, and advance ptr

    - advancing(): if right is null: pop from vec
        - so go to right (if not null) else pop from vec
        - then go to the LEFTMOST node!

    - has next:
      - if not null && (has right or q not empty)

    */

  }

  void advanceIterator() {
    if (it->right)  { // there is a right subtree already
      it=it->right;
      // can have a smaller val
      while(it->left) it=it->left;
    } else { // pop an element from queue
      it = backlinks.empty() ? nullptr : backlinks.front();
      backlinks.pop();
      // NOTE: we should NOT go back left again!
      // since we are utilizing a backlink
      // it means we are done with the subtree that is left of the backlink itself
    }
  }

  int next() {
    if (it==nullptr) return INT_MIN;

    int res = it->val;
    advanceIterator();
    return res;
  }

  bool hasNext() {
    // we are AT the next node
    // so the right is actually next of next
    return it;  // if it exists we are not done
  }
};



#include <stack>
using namespace std;

class BSTIteratorStack {
  stack<TreeNode*> st;

  void appendNodeAndLefts(TreeNode* node) {
    while(node) {
      st.push(node);
      node=node->left;
    }
  }
 public:
  BSTIterator(TreeNode* root) {
    if (root) appendNodeAndLefts(root);
  }

  int next() {
    if (st.empty()) return INT_MIN;

    auto node = st.top(); st.pop();
    int res = node->val;
    if (node->right) appendNodeAndLefts(node->right);
    return res;
  }

  bool hasNext() {
    return !st.empty();
  }
};