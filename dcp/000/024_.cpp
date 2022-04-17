

class Node {
 public:
  bool locked {};
  int child_locks {};

  bool any_parent_locked() {
    auto node = parent;
    while (node) {
      if (node->locked) return true;
      node=node->parent;
    }
    return false;
  }



 public:

  Node *left{}, *right{}, *parent{};

  bool is_locked() { return locked; }

  bool lock() {
    if (any_parent_locked()) return false;
    else if (child_locks>0) return false;

    locked=true;

    auto node=parent;
    while (node) {
      node->child_locks++;
      node=node->parent;
    }
    return true;
  }

  bool unlock() {
    if (!locked)  return false;

    locked=false;
    auto node=parent;
    while (node) {
      node->child_locks--;
      node=node->parent;
    }
    return true;
  }

};



#include "test/024.h"
int main() { run_tests(); return 0; }