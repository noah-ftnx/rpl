#include <stack>
#include <string>
using namespace std;

class Queue {
 private:
  stack<int> st1; // can deque directly

 public:
  void enqueue(int num) {
    stack<int> tmp;
    // st1: 3 2 1
    // tmp:
    while (!st1.empty()) {
      tmp.push(st1.top()); st1.pop();
    }

    st1.push(num);

    while (!tmp.empty()) {
      st1.push(tmp.top()); tmp.pop();
    }
  }

  int dequeue() {
    if (st1.empty()) throw string("queue is empty");

    int res = st1.top();
    st1.pop();
    return res;
  }
};



#include "test/053.h"
int main() { run_tests(); return 0; }