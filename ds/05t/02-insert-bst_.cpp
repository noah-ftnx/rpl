#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;


template <class T>
struct Node {
  Node<T>* left {};
  Node<T>* right {};
  Node<T>* parent {};
  T data;

  Node(T data) : data{data} {
  }
  ~Node() {
    if (left) {
      delete left;
      left = nullptr;
    }
    if (right) {
      delete right;
      right=nullptr;
    }
  }
};


template <class T>
class BSTree {
 private:
  Node<T>* root {};
 public:
  explicit BSTree() = default;

  ~BSTree() {
    delete root;
  }

  void insert(vector<T> vec) { for (auto v: vec) insert(v); }

  void _insert(T data, Node<T>* node) {
    if (data > node->data)  { // insert: Right
      if (!node->right) {
        node->right = new Node(data);
        node->right->parent=node;
      }
      else _insert(data, node->right);
    } else { // insert: Left
      if (!node->left) {
        node->left = new Node(data);
        node->left->parent=node;
      }
      else _insert(data, node->left);
    }
  }

  void insert(T data) {
    if (root == nullptr) { root = new Node(data); }
    else {
      _insert(data, root);
    }
  }

  ///////////// for verification
  string __get_bfs() {
    queue<Node<T>*> q;
    q.push(root);
    string r;
    while (!q.empty()) {
      auto n=q.front();
      q.pop();
      r+= std::to_string(n->data) + " ";
      if (n->left) q.push(n->left);
      if (n->right) q.push(n->right);
    }
    return r;
  }
  /////////////
};


string correct_bfs="35 15 45 20 70 60 73 50 ";

void run_tests() {
  auto t1= new BSTree<int>();
  vector<int> v1 {35, 15, 20, 45, 70, 60, 73, 50};
  t1->insert(v1);
  string s = t1->__get_bfs();
  cout << s  << (s.compare(correct_bfs)!=0?" (WRONG)": "")<< endl;
}

int main() { run_tests(); return 0; }