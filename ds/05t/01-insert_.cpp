#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class Node {
 public:
  T data {};
  Node<T>* left {};
  Node<T>* right {};
  Node<T>* parent {};

  explicit Node(T data) : data{data} {}
  ~Node() { clear(); }

  void clear() {
    if(left) {
      delete left;
      left=nullptr;
    }
    if (right) {
      delete right;
      right=nullptr;
    }
  }
};

template <class T>
class Tree {
 private:
  Node<T>* root {};
 public:

  // CONSTRUCTORS / INSERTION
  explicit Tree() = default;

  explicit Tree(T root_value) {
    root = new Node<T>(root_value);
  }

  explicit Tree(Node<T>* root) : root{root} {}

  ~Tree() {
    delete root;
  }

  void add(const vector<T>& data, const string& path) {
    if(data.size() != (path.size())) { cout << "ERR\n"; exit(-1); }

    Node<T>* node = root;
    auto itd=data.begin();
    auto itp=path.begin();
    for(; itd!=data.end(); itd++, itp++) {
      if(*itp=='L') { // LEFT NODE
        if (node->left == nullptr) {
          node->left = new Node<T>(*itd);
          node->left->parent = node;
        } else {
          assert(node->left->data == *itd);
        }
        node = node->left;
      } else if(*itp=='R') { // RIGHT NODE
        if(node->right == nullptr) {
          node->right = new Node<T>(*itd);
          node->right->parent=node;
        } else {
          assert(node->right->data == *itd);
        }
        node=node->right;
      }
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



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------




vector<string> correct_bfs {
    "1 2 4 5 8 9 10 11 ",
    "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 ",
};

void run_tests() {
  auto tree = Tree<int>(1);
  tree.add( { 2, 4, 8 }, { 'L', 'L', 'L' });
  tree.add( { 2, 4, 9 }, { 'L', 'L', 'R' });
  tree.add( { 2, 5, 10 }, { 'L', 'R', 'L' });
  tree.add( { 2, 5, 11 }, { 'L', 'R', 'R' });
  string ss1=tree.__get_bfs();
  cout << ss1  << (ss1.compare(correct_bfs[0])!=0?" (WRONG)": "")<< endl;

  tree.add( { 3, 6, 12 }, { 'R', 'L', 'L' });
  tree.add( { 3, 6, 13 }, { 'R', 'L', 'R' });
  tree.add( { 3, 7, 14 }, { 'R', 'R', 'L' });
  tree.add( { 3, 7, 15 }, { 'R', 'R', 'R' });
  string ss2=tree.__get_bfs();
  cout << ss2  << (ss2.compare(correct_bfs[1])!=0?" (WRONG)": "")<< endl;
}


int main() { run_tests(); }