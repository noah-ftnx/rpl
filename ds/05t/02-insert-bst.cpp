#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Node {
  int data {};
  Node* left {};
  Node* right {};

  explicit Node(int data) : data{data} {}
};

class BSTree {
 private:
  Node* root {};

 public:
  // Implement these:
  void insert(int data);
  void insert(const vector<int>& values);

  string bfs() {
    if (!root) return "";

    queue<Node*> q;
    q.push(root);

    string result;
    while (!q.empty()) {
      auto node = q.front();
      q.pop();

      result += to_string(node->data) + " ";
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
    return result;
  }
};

void check(vector<int> values, string expected) {
  BSTree tree;
  tree.insert(values);

  string result = tree.bfs();
  cout << (result == expected ? "[PASS] " : "[FAIL] ") << result << endl;
}

void run_tests() {
  check({}, "");
  check({35}, "35 ");
  check({10, 5, 15, 3, 7, 12, 18}, "10 5 15 3 7 12 18 ");
  check({35, 15, 20, 45, 70, 60, 73, 50}, "35 15 45 20 70 60 73 50 ");
}

int main() { run_tests(); return 0; }
