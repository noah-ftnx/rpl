

class Node {
 private:
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

  bool lock_mechanism_blocked() {
    if (child_locks>0) return true;
    return any_parent_locked();
  }

 public:

  Node *left{}, *right{}, *parent{};

  bool is_locked() { return locked; }

  bool lock() {
    if (!lock_mechanism_blocked()) {
      locked=true;

      auto node=parent;
      while (node) {
        node->child_locks++;
        node=node->parent;
      }

      return true;
    }
    return false;
  }

  bool unlock() {
    if (!lock_mechanism_blocked()) {
      locked=false;
      auto node=parent;
      while (node) {
        node->child_locks--;
        node=node->parent;
      }
      return true;
    }
    return false;
  }

};



#include "test/024.h"
int main() { run_tests(); return 0; }