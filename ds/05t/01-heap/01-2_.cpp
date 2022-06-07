// INCLUDES here
#include<vector>
using namespace std;

#include "test/heap.h"

/*
 * @param input unsorted array
 */
MinHeap::MinHeap(const vector<int>& input) {
  for (auto i: input) vec.push_back(i);

  heapify();
}

MinHeap::~MinHeap() {
  vec.clear();
}

void MinHeap::heapify() { // floyd heapify:
  for (int i= vec.size()/2; i>=0; i--) { // O(N) to create the heap
    percolate_down(i);
  }
}

int MinHeap::left(int idx) {
  int ch = (2*idx)+1;
  return ch>=size()? -1 : ch;
}

int MinHeap::right(int idx) {
  int ch = (2*idx)+2;
  return ch>=size()? -1 : ch;
}

void MinHeap::percolate_down(int idx) {
  // while idx is bigger than any of each child
  // swap with the smallest one
  // stop when not bigger than any of them

  while (true) {
    int L = left(idx);
    int R = right(idx);

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

#include "test/01-2.h"
int main() {
  run_tests("heapify");

  print_report();
  return 0;
}
