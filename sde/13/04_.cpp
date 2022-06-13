#include <stack>
using namespace std;

class MyQueue {
 public:
  // s: 1, 2
  // t: 2, 1 step1: add all elements of s
  // t: 3, 2, 1 step 2: add new element
  // step 2: add back to st
  // s: 1, 2, 3

  stack<int> st;

  MyQueue() {

  }

  void push(int x) {
    stack<int> tmp;
    while(!st.empty()) {
      tmp.push(st.top()); st.pop();
    }
    tmp.push(x);

    // add back to st
    while(!tmp.empty()) {
      st.push(tmp.top()); tmp.pop();
    }
  }

  int pop() {
    if (empty()) return -1;
    int res = st.top();
    st.pop();
    return res;
  }

  int peek() {
    if (empty()) return -1;
    return st.top();
  }


  bool empty() {
    return st.empty();
  }
};


class MyQueueFollowupComplex {
 public:
  stack<int> st; // if non empty: we have to applyCorrection
  stack<int> ordered;

  MyQueue() { }

  void push(int x) {
    st.push(x);
    // defer correction
    // if many consecutive push are done,
    // only one correction will be triggered
  }

  void applyCorrection() {
    stack<int> tmp;
    while(!st.empty()) { tmp.push(st.top()); st.pop(); }

    // 2. add from ordered to st
    while(!ordered.empty()) { st.push(ordered.top()); ordered.pop(); }

    // 3. add from tmp to st (st has eveythng now, but reversed)
    while (!tmp.empty()) { st.push(tmp.top()); tmp.pop(); }

    // 4. add st back to ordered
    while (!st.empty()) { ordered.push(st.top()); st.pop(); }
  }

  int pop() {
    int res = peek();
    if (res==-1) return -1;

    ordered.pop();
    return res;
  }

  int peek() {
    if (empty()) return -1;

    // if many peeks are requested:
    // only on correction will be done
    if (!st.empty()) applyCorrection();

    return ordered.top();
  }

  size_t size() { return st.size() + ordered.size(); }
  bool empty() { return size()==0; }
};


class MyQueueFollowupOPT {
 public:

  stack<int> input;  // not in FIFO orderclass MyQueueFollowupOPT {
 public:

  stack<int> input;  // not in FIFO order
  stack<int> output; // its in FIFO order (correct)

  MyQueue() { }

  void push(int x) {
    input.push(x);
  }

  int pop() {
    int res = peek();
    if (res==-1) return -1;
    output.pop();

    return res;
  }

  int peek() {
    if (empty()) return -1;

    if (output.empty()) { // must compute FIFO ordered output
      // input:  3 2 1
      // output: 1 2 3
      while (!input.empty()) {
        output.push(input.top()); input.pop();
      }
    }

    // we have (some) FIFO ordered outpout computed
    return output.top();
  }

  bool empty() { return size()==0; }

  size_t size() { return input.size() + output.size(); }
}
  stack<int> output; // its in FIFO order (correct)

  MyQueue() { }

  void push(int x) {
    input.push(x);
  }

  int pop() {
    int res = peek();
    if (res==-1) return -1;
    output.pop();

    return res;
  }

  int peek() {
    if (empty()) return -1;

    if (output.empty()) { // must compute FIFO ordered output
      // input:  3 2 1
      // output: 1 2 3
      while (!input.empty()) {
        output.push(input.top()); input.pop();
      }
    }

    // we have (some) FIFO ordered outpout computed
    return output.top();
  }

  bool empty() { return size()==0; }

  size_t size() { return input.size() + output.size(); }
};