#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

template <class T>
struct Node {
  Node<T>* left {};
  Node<T>* right {};
  Node<T>* parent {};
  T data;

  explicit Node(T data) : data{data} {}

  ~Node() {
    delete left;
    delete right;
  }
};

template <class T>
class BSTree {
 private:
  Node<T>* root {};

 public:
  explicit BSTree() = default;
  ~BSTree() { delete root; }

  // Implement:
  void insert(vector<T> vec);
  void insert(T data);
  void _insert(T data, Node<T>* node);

  string __get_bfs() {
    if (!root) return "";

    queue<Node<T>*> q;
    q.push(root);

    string res;
    while (!q.empty()) {
      auto node = q.front();
      q.pop();

      res += to_string(node->data) + " ";
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
    return res;
  }
};

const string correct_bfs = "35 15 45 20 70 60 73 50 ";

void run_tests() {
  BSTree<int> t1;
  vector<int> v1 {35, 15, 20, 45, 70, 60, 73, 50};

  t1.insert(v1);
  string s = t1.__get_bfs();

  cout << (s == correct_bfs ? "[PASS] " : "[FAIL] ") << s << endl;
}

int main() { run_tests(); return 0; }
