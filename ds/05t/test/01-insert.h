#ifndef RPL_DS_05T_TEST_01_INSERT_H_
#define RPL_DS_05T_TEST_01_INSERT_H_

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

template <class T>
string bfs(Tree<T>& tree) {
  queue<Node<T>*> q;
  q.push(tree.root);

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

void check(Tree<int>& tree, const string& expected) {
  string result = bfs(tree);
  cout << (result == expected ? "[PASS] " : "[FAIL] ") << result;
  if (result != expected) cout << "Expected: " << expected;
  cout << endl;
}

void run_tests() {
  Tree<int> tree(1);

  tree.add({2, 4, 8}, "LLL");
  tree.add({2, 4, 9}, "LLR");
  tree.add({2, 5, 10}, "LRL");
  tree.add({2, 5, 11}, "LRR");
  check(tree, "1 2 4 5 8 9 10 11 ");

  tree.add({3, 6, 12}, "RLL");
  tree.add({3, 6, 13}, "RLR");
  tree.add({3, 7, 14}, "RRL");
  tree.add({3, 7, 15}, "RRR");
  check(tree, "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 ");
}

#endif  // RPL_DS_05T_TEST_01_INSERT_H_
