
#include <exception>
using namespace std;

struct Node {
  Node* next {};
  int val;
  Node(int val) : val{val} {}
};

using namespace std;

class Stack {
 private:
  Node* top {};
  Node* mx_top {};

  void check_not_empty() { if (top == nullptr) throw "empty stack"; }

 public:

  void push(int val) {
    auto node = new Node(val);
    node->next=top;
    top=node;

    if (mx_top == nullptr) {
      mx_top=new Node(val);
    } else if(val >= mx_top->val) { // handle duplicates
      // 5 3 4 10:    st:   10 4 3 5
      //           maxst:	  10 5
      auto new_mx = new Node(val);
      new_mx->next=mx_top;
      mx_top=new_mx;
    }
  }

  int pop() {
    check_not_empty();

    auto old = top;
    top=top->next;
    int res = old->val;
    delete old;
    if (mx_top->val == res) {
      auto oldmx = mx_top;
      mx_top=mx_top->next;
      delete oldmx;
    }

    return res;
  }

  int max() {
    check_not_empty();

    return mx_top->val;
  }
};



#include "test/043.h"
int main() { run_tests(); return 0; }