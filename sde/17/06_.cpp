#include <vector>
using namespace std;

void fillLeftView(TreeNode<int>* node, int level, int &mxLevel, vector<int> &res) {
  if (node==nullptr) return;

  if (++level > mxLevel) {
    mxLevel=level;
    res.push_back(node->data);
  }

  fillLeftView(node->left, level, mxLevel, res);
  fillLeftView(node->right, level, mxLevel, res);
  --level;
}

vector<int> getLeftView(TreeNode<int> *root) {
  vector<int> res;
  int mxLevel=-1;
  fillLeftView(root, -1, mxLevel, res);

  return res;
}




// VARIANT 2:
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root) {
  vector<int> result;
  auto node = root;
  // print the left side
  while (node) {
    result.push_back(node->data);
    if (node->left == nullptr) break;
    else node=node->left;
  }

  // print any right nodes at the end
  while(node->right) {
    node=node->right;
    result.push_back(node->data);
  }
  return result;
}
