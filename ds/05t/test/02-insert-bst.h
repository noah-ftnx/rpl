#ifndef RPL_DS_05T_TEST_02_INSERT_BST_H_
#define RPL_DS_05T_TEST_02_INSERT_BST_H_

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

string bfs(Node* root) {
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

void check_vector(vector<int> values, string expected) {
  BSTree tree;
  tree.insert(values);

  string result = bfs(tree.root);
  cout << (result == expected ? "[PASS] " : "[FAIL] ") << result;
  if (result != expected) cout << "Expected: " << expected;
  cout << endl;
}

void check_single_inserts(vector<int> values, string expected) {
  BSTree tree;
  for (auto value: values) tree.insert(value);

  string result = bfs(tree.root);
  cout << (result == expected ? "[PASS] " : "[FAIL] ") << result;
  if (result != expected) cout << "Expected: " << expected;
  cout << endl;
}

void run_tests() {
  check_vector({}, "");
  check_vector({35}, "35 ");
  check_single_inserts({10, 5, 15, 3, 7, 12, 18}, "10 5 15 3 7 12 18 ");
  check_vector({35, 15, 20, 45, 70, 60, 73, 50}, "35 15 45 20 70 60 73 50 ");
}

#endif  // RPL_DS_05T_TEST_02_INSERT_BST_H_
