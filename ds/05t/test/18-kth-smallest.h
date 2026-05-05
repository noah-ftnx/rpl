#ifndef RPL_DS_05T_TEST_18_KTH_SMALLEST_H_
#define RPL_DS_05T_TEST_18_KTH_SMALLEST_H_

#include <cassert>
#include <iostream>
#include <optional>
#include <string>
#include <vector>
using namespace std;

template <class T>
class Node {
 public:
  T data {};
  Node* left {};
  Node* right {};
  Node* parent {};

  explicit Node(T data) : data{data} {}

  ~Node() { clear(); }

  void clear() {
    if (left) { delete left; left = nullptr; }
    if (right) { delete right; right = nullptr; }
  }
};

template <class T>
class Tree {
 private:
  Node<T>* root {};

 public:
  Tree() = default;
  explicit Tree(T data) : root{new Node<T>(data)} {}
  ~Tree() { delete root; }

  void add(const vector<T>& data, const string& path) {
    assert(data.size() == path.size());

    Node<T>* node = root;
    auto itd = data.begin();
    auto itp = path.begin();
    for (; itd != data.end(); itd++, itp++) {
      if (*itp == 'L') {
        if (!node->left) {
          node->left = new Node<T>(*itd);
          node->left->parent = node;
        } else {
          assert(node->left->data == *itd);
        }
        node = node->left;
      } else if (*itp == 'R') {
        if (!node->right) {
          node->right = new Node<T>(*itd);
          node->right->parent = node;
        } else {
          assert(node->right->data == *itd);
        }
        node = node->right;
      }
    }
  }

  void init_input1() {
    root = new Node<T>(10);
    add({5, 3}, "LL");
    add({5, 7}, "LR");
    add({25, 20}, "RL");
    add({25, 30}, "RR");
  }

  void init_left_chain() {
    root = new Node<T>(4);
    add({3, 2, 1}, "LLL");
  }

  void init_right_chain() {
    root = new Node<T>(1);
    add({2, 3, 4}, "RRR");
  }

  optional<T> kth_smallest(int k);
};

template <class T>
string show(optional<T> value) {
  if (!value) return "<none>";
  return to_string(*value);
}

template <class T>
void check_optional(string msg, optional<T> result, optional<T> correct) {
  bool wrong = result != correct;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << msg << ": " << show(result);
  if (wrong) cout << " Expected: " << show(correct);
  cout << endl;
}

void run_tests() {
  auto tree1 = Tree<int>();
  check_optional("kth:1 empty k=1", tree1.kth_smallest(1), optional<int>{});

  auto tree2 = Tree<int>();
  tree2.init_input1(); // inorder: 3 5 7 10 20 25 30
  check_optional("kth:2 k=0", tree2.kth_smallest(0), optional<int>{});
  check_optional("kth:3 k=1", tree2.kth_smallest(1), optional<int>{3});
  check_optional("kth:4 k=3", tree2.kth_smallest(3), optional<int>{7});
  check_optional("kth:5 k=4", tree2.kth_smallest(4), optional<int>{10});
  check_optional("kth:6 k=7", tree2.kth_smallest(7), optional<int>{30});
  check_optional("kth:7 k=8", tree2.kth_smallest(8), optional<int>{});

  auto tree3 = Tree<int>();
  tree3.init_left_chain(); // inorder: 1 2 3 4
  check_optional("kth:8 left chain k=2", tree3.kth_smallest(2), optional<int>{2});

  auto tree4 = Tree<int>();
  tree4.init_right_chain(); // inorder: 1 2 3 4
  check_optional("kth:9 right chain k=4", tree4.kth_smallest(4), optional<int>{4});

  cout << endl;
}

#endif  // RPL_DS_05T_TEST_18_KTH_SMALLEST_H_
