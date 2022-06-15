
#include <queue>
using namespace std;

class SolutionExtraSpace {
 public:
  Node* connect(Node* root) {
    if (root==nullptr) return nullptr;
    queue<Node*> q;

    q.push(root);
    while (!q.empty()) {
      int sz = q.size();
      while(sz--) {
        auto node=q.front(); q.pop();
        node->next= sz>0? q.front() : nullptr; // TRICKY

        if (node->left) { // has both left and right
          q.push(node->left);
          q.push(node->right);
        }
      }
    }

    return root;
  }
};


class SolutionRecursive {
 public
  Node* connect(Node* root) {
    if (root==nullptr) return nullptr;
    // leaf node: will be taken care by the parent node
    if (root->left == nullptr && root->right == nullptr) return root;

    // visit: link child
    root->left->next=root->right;
    if(root->next) {
      // link between subtrees:
      // if it has next: then it's neighbor must have 2 child
      // link the last of the left subtree to the first of the other
      root->right->next=root->next->left;
    }

    // traverse tree
    // connect(root->next); // NO NEED.
    connect(root->left);
    connect(root->right);

    return root;
  }
};