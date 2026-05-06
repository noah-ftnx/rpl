#include <vector>
using namespace std;

// Return true if vec satisfies MinHeap order.
bool is_min_heap(const vector<int> &vec) {
  const int N = (int) vec.size();

  for (int i = 0; i < N; i++) {
    int L = 2*i + 1;
    int R = 2*i + 2;

    if (L < N && vec[L] < vec[i]) return false;
    if (R < N && vec[R] < vec[i]) return false;
  }

  return true;
}

#include "test/03-check-array-is-heap.h"
int main() { run_tests(); return 0; }
