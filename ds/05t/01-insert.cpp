#include <string>
#include <vector>
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
    if (left) {
      delete left;
      left = nullptr;
    }
    if (right) {
      delete right;
      right = nullptr;
    }
  }
};

template <class T>
class Tree {
 public:
  Node<T>* root {};

  explicit Tree() = default;

  explicit Tree(T root_value) {
    root = new Node<T>(root_value);
  }

  explicit Tree(Node<T>* root) : root{root} {}

  ~Tree() {
    delete root;
  }

  // IMPLEMENT: add path values
  void add(const vector<T>& data, const string& path);
};

#include "test/01-insert.h"
int main() { run_tests(); return 0; }
