#include <deque>
#include <vector>
using namespace std;

struct Node {
  Node *left{}, *right{};
  char data;

  Node(char d) : data{d} {};
};


Node* build_tree(deque<char>& preorder, vector<char> inorder,
                 int L=0, int R=-1) {
  if(R==-1) R=inorder.size()-1;

  Node* node = new Node(preorder.front()); preorder.pop_front();

  for (int i=L; i<=R; i++) {
    if (inorder[i]==node->data) { // found split point
      if (i>L) node->left=build_tree(preorder, inorder, L, i-1);
      if (i<R) node->right=build_tree(preorder, inorder, i+1, R);
    }
  }

  return node;
}



#include "test/048.h"
int main() { run_tests(); return 0; }