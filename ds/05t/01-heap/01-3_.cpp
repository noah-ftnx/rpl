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

void percolate_down(vector<int> &vec, int idx, int customSize=-1) {
  // while idx is bigger than any of each child
  // swap with the smallest one
  // stop when not bigger than any of them

  const int size = customSize>=0? customSize : (int) vec.size();
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

int top(vector<int> &vec) { return vec[0]; }

void pop(vector<int> &vec) {
  // remove the top:
  // copy last element to top, decrease size.
  // percolate top down

  int last = vec[vec.size()-1];
  vec.resize(vec.size()-1);

  vec[0]=last;
  percolate_down(vec, 0);
}

void heapsort(vector<int> &vec) { // extra space
  heapify(vec);

  // using additional space
  vector<int> res;
  while(!vec.empty()) {
   res.push_back(top(vec));
   pop(vec);
  }

  vec=res;
}

void heapsortInPlace(vector<int> &vec) {
  heapify(vec);
  int sortedIdx=vec.size(); // invalid index
  while (sortedIdx-->=0) {
    // put min in last position
    int mnVal = vec[0];
    // swap min with last value
    swap(vec[0], sortedIdx);

    // perc down the new top (but w/ decreased size)
    percolate_down(vec, 0, sortedIdx);
  }

  // reverse at the end
  reverse(vec.begin(), vec.end());
}

#include "test/01-3.h"
int main() {
  run_tests(heapify, "heapify");
  run_tests(heapify, "heapifyInPlace");

  print_report();
  return 0;
}
