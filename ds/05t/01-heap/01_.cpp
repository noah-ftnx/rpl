#include <vector>
using namespace std;

class MinHeap {
private:
  vector<int> vec;

  int left(int i) const {
    int ch = 2*i + 1;
    return ch < size() ? ch : -1;
  }

  int right(int i) const {
    int ch = 2*i + 2;
    return ch < size() ? ch : -1;
  }

  int parent(int i) const {
    return i == 0 ? -1 : (i - 1) / 2;
  }

  void percolate_up(int i) {
    int p;
    while ((p = parent(i)) != -1 && vec[i] < vec[p]) {
      swap(vec[i], vec[p]);
      i = p;
    }
  }

  void percolate_down(int i) {
    while (true) {
      int L = left(i);
      int R = right(i);
      if (L == -1) break;

      int mn = L;
      if (R != -1 && vec[R] < vec[L]) mn = R;

      if (vec[i] <= vec[mn]) break;
      swap(vec[i], vec[mn]);
      i = mn;
    }
  }

public:
  bool empty() const { return vec.empty(); }
  int size() const { return (int) vec.size(); }
  int top() const { return vec[0]; }

  void push(int v) {
    vec.push_back(v);
    percolate_up(size() - 1);
  }

  void pop() {
    vec[0] = vec.back();
    vec.pop_back();
    if (!empty()) percolate_down(0);
  }
};

#include "test/01.h"
int main() {
  run_tests("implement heap");
  print_report();
  return 0;
}
