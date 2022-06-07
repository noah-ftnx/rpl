#include <vector>
using namespace std;

int left(int size, int idx) {
  int ch = (2*idx)+1;
  return ch>=size? -1 : ch;
}

int right(int size, int idx) {
  int ch = (2*idx)+2;
  return ch>=size? -1 : ch;
}

void percolate_down(vector<int> &vec, int idx) {
  // while idx is bigger than any of each child
  // swap with the smallest one
  // stop when not bigger than any of them

  const int size = (int) vec.size();
  while (true) {
    int L = left(size, idx);
    int R = right(size, idx);

    // if no left child, there can't be a right child
    // heaps are complete trees
    if (L==-1) break;

    // find min child
    int minChild=L; // assumption
    if (R>=0 && vec[R] < vec[L]) minChild=R;

    if (vec[minChild] < vec[idx]) {
      swap(vec[minChild], vec[idx]);
      idx=minChild;
    } else break; // from this point and below it's already a heap
  }
}

void heapify(vector<int> &vec) { // floyd heapify:
  for (int i= vec.size()/2; i>=0; i--) { // O(N) to create the heap
    percolate_down(vec, i);
  }
}

#include "test/01-2.h"
int main() {
  run_tests("heapify");

  print_report();
  return 0;
}
