#include <functional>
#include <vector>
using namespace std;

// MinHeap array input.
// Return all values less than val.
vector<int> nodes_less_than(const vector<int> &heap, int val) {
  vector<int> res;

  auto left = [&](int i) {
    int child = 2*i + 1;
    return child < (int)heap.size() ? child : -1;
  };

  auto right = [&](int i) {
    int child = 2*i + 2;
    return child < (int)heap.size() ? child : -1;
  };

  function<void(int)> dfs = [&](int i) {
    if (i == -1) return;
    if (heap[i] >= val) return;

    res.push_back(heap[i]);
    dfs(left(i));
    dfs(right(i));
  };

  dfs(heap.empty() ? -1 : 0);
  return res;
}

#include "test/02-print-less-than.h"
int main() { run_tests(); return 0; }
