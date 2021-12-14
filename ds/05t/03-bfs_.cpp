#include <iostream>
#include <queue>
using namespace std;

class Node {
 public:
  int data {};
  Node* left {};
  Node* right {};

  explicit Node(int data) : data{data} {}

  ~Node() { clear(); }

  void clear() {
    if(left) { delete left; left=nullptr; }
    if (right) { delete right; right=nullptr; }
  }
};

class Tree {
 public:
  Node* root {};
  explicit Tree() = default;
  ~Tree() { delete root; }

  void print_bfs() {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
      auto node = q.front(); q.pop();
      cout << node->data << " ";
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
    cout << endl;
  }
};

void run_tests() {
  auto t = Tree();
  t.root = new Node(10);
  t.root->left=new Node(5);
  t.root->right=new Node(25);
  t.root->right->left=new Node(20);
  t.root->right->right=new Node(30);
  t.root->left->right=new Node(7);
  t.root->left->left=new Node(3);

  cout << "VERIFY MANUALLY:\n";
  t.print_bfs();
  cout << "10 5 25 3 7 20 30 <- correct output\n";
}

int main () { run_tests(); }