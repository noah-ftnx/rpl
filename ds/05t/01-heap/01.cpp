#include <vector>
using namespace std;

class MinHeap {
private:
  vector<int> vec;

  int left(int i) const;
  int right(int i) const;
  int parent(int i) const;

  void percolate_up(int i);
  void percolate_down(int i);

public:
  bool empty() const;
  int size() const;
  int top() const;

  void push(int v);
  void pop();
};

#include "test/01.h"
int main() {
  run_tests("implement heap");
  print_report();
  return 0;
}
