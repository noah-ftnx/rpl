#include <vector>
#include <queue>
using namespace std;

class Processor {
 private:
  priority_queue<int, vector<int>, less<int>> left;     // max heap
  priority_queue<int, vector<int>, greater<int>> right; // min heap

 public:
  void insert(int element) {
    if (left.empty() || element <= left.top()) { // add to left
      left.push(element);
    } else {
      right.push(element);
    }
    if (right.size() > left.size()) { // move an element to the left side
      left.push(right.top());
      right.pop();
    } else if (left.size() - right.size() >1) { // move one element to the right side
      right.push(left.top());
      left.pop();
    }
  }

  double median() {
    if ((left.size()+right.size()) % 2 ==0) {  // TRICKY parenthesis
      return ((double)left.top()+right.top())/2.0;
    } else {
      return left.top();
    }
  }
};



#include "test/033.h"
int main() { run_tests(); return 0; }