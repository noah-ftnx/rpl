#include <vector>
using namespace std;

int left(int size, int idx) {
  int ch = 2*idx + 1;
  return ch < size ? ch : -1;
}

int right(int size, int idx) {
  int ch = 2*idx + 2;
  return ch < size ? ch : -1;
}

void percolate_down(vector<int> &vec, int idx, int size) {
  while (true) {
    int L = left(size, idx);
    int R = right(size, idx);
    if (L == -1) break;

    int mx = L;
    if (R != -1 && vec[R] > vec[L]) mx = R;

    if (vec[idx] >= vec[mx]) break;
    swap(vec[idx], vec[mx]);
    idx = mx;
  }
}

void heapify(vector<int> &vec) {
  for (int i = (int) vec.size()/2 - 1; i >= 0; i--)
    percolate_down(vec, i, vec.size());
}

void heapsort(vector<int> &vec) {
  heapify(vec);

  for (int size = (int) vec.size(); size > 1; size--) {
    swap(vec[0], vec[size - 1]);
    percolate_down(vec, 0, size - 1);
  }
}

#include "test/01-3.h"
int main() {
  run_tests(heapsort, "heapsort");
  print_report();
  return 0;
}
