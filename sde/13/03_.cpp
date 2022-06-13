#include <queue>
using namespace std;

class MyStack {
 public:
  queue<int> q;

  MyStack() {}

  void push(int x) {
    queue<int> tmp;
    tmp.push(x);

    // put elements from q too:
    while (!q.empty()) {
      tmp.push(q.front()); q.pop();
    }
    q=tmp;
  }

  int pop() {
    if (empty()) return -1;
    int res=q.front();
    q.pop();
    return res;
  }

  int top() {
    if (empty()) return -1;
    return q.front();
  }

  bool empty() {
    return q.empty();
  }
};


void pushSingleQueue(int x) {
  q.push(x);

  // we have to do some pops, and put those elements to the back
  // this will put x in the front
  int pops=q.size()-1;

  while(pops--) {
    int el = q.front(); q.pop();
    q.push(el);
  }
}