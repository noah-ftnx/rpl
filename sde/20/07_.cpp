Node* findPre(Node* root, int key) {
  // find predecessor
  auto node = root;
  Node *pre=nullptr;
  Node *prev=nullptr;
  while (node && node->key != key) { // until we find the key
    prev=node;
    if (node->key > key) node=node->left;
    else {
      pre=node;// also found a candidate
      node=node->right;
    }
  }
    
  // node might be missing: in that case we already found pre
  if (node && node->left) {
    node=node->left;
    while(node->right) node=node->right;
    pre=node;
  }

  return pre;
}

Node* findSuc(Node* root, int key) {
  Node* suc=nullptr;
  auto node = root;
  while (node && node->key != key) {
    if (node->key > key) {
      suc=node; // also found a candidate
      node=node->left;
    } else node=node->right;
  }

  // there are bigger nums: pick the min amongst them
  if (node && node->right) {
    node=node->right;
    while(node->left) node=node->left;
    suc=node;
  }
    
  return suc;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
  pre=findPre(root, key);
  suc=findSuc(root, key);
}






////////////
/*************************************************************

Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
{
 public :
  T data;
  BinaryTreeNode<T> *left;
  BinaryTreeNode<T> *right;

  BinaryTreeNode(T data) {
    this -> data = data;
    left = NULL;
    right = NULL;
  }

  ~BinaryTreeNode() {
    if (left)
    {
      delete left;
    }
    if (right)
    {
      delete right;
    }
  }
};

*************************************************************/

int findPredecessor(BinaryTreeNode<int> *root, int key) {
  BinaryTreeNode<int>* pred=nullptr;

  while (root) {
    if (key <= root->data) { // node is bigger
      root=root->left;
    } else {
      // node is smaller
      pred=root;
      root=root->right;
    }
  }

  return pred==nullptr? -1 : pred->data;
}

int findSuccessor(BinaryTreeNode<int> *root, int key) {
  BinaryTreeNode<int>* succ=nullptr;

  while(root) {
    if (key >= root->data) { // node is smaller
      root=root->right;
    } else {
      succ=root;
      root=root->left;
    }
  }

  return succ==nullptr? -1 : succ->data;
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key) {
  return { findPredecessor(root, key),
          findSuccessor(root, key)};
}
