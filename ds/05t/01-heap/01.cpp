#include <vector>
using namespace std;

class MinHeap {
private:
  vector<int> vec;

  // IMPLEMENT: left
  int left(int i) const;
  // IMPLEMENT: right
  int right(int i) const;
  // IMPLEMENT: parent
  int parent(int i) const;

  // Why needed?
  // IMPLEMENT: percolate_up
  void percolate_up(int i);

  // Why needed?
  // IMPLEMENT: percolate_down
  void percolate_down(int i);

public:
  // IMPLEMENT: empty
  bool empty() const;
  // IMPLEMENT: size
  int size() const;
  // IMPLEMENT: top
  int top() const;

  // IMPLEMENT: push
  void push(int v);
  // IMPLEMENT: pop
  void pop();
};

#include "test/01.h"
int main() {
  run_tests("implement heap");
  print_report();
  return 0;
}
