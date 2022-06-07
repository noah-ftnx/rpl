// INCLUDES here
#include<vector>
using namespace std;

#include "test/heap.h"


/*
 * @param input unsorted array
 */
MinHeap::MinHeap(const vector<int>& input) {
  for (auto i: input) vec.push_back(i);

  heapsort();
}

MinHeap::~MinHeap() {
  vec.clear();
}

void MinHeap::heapsort() { // floyd heapify:
  for (int i= vec.size()/2; i>=0; i--) { // O(N) to create the heap
    percolate_down(i);
  }
  // then pop from the heap and put to result
  vector<int> res;
  while (size()) {
    res.push_back(top());
    pop();
  }

  vec=res; // assign sorted array
}

// METHODS ARE MISSING
// Implement all required in order to support the below:
// then check on the names w/ the .h

void MinHeap::push(int v) {
  // increase and push element to last pos
  // then percolade it up

  int idx=size();
  vec.resize(idx+1);
  vec[idx]=v;
  percolate_up(idx);
}

int MinHeap::top() { return vec[0]; }

void MinHeap::pop() {
  // remove the top:
  // copy last element to top, decrease size.
  // percolate top down

  int last = vec[size()-1];
  vec.resize(size()-1);

  vec[0]=last;
  percolate_down(0);
}


int MinHeap::left (int idx) {
  int ch = (2*idx)+1;
  return ch>=size()? -1 : ch;
}

int MinHeap::right(int idx) {
  int ch = (2*idx)+2;
  return ch>=size()? -1 : ch;
}

int MinHeap::parent(int idx) {
  return idx==0? -1 : (idx-1)/2;
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

void MinHeap::percolate_up(int idx) {
  while (parent(idx)>=0) {
    if (vec[idx] < vec[parent(idx)]) {
      swap(vec[idx], vec[parent(idx)]);
      idx=parent(idx);
    } else break;
  }
}

#include "test/01-2.h"
int main() {
  run_tests("heapify");

  print_report();
  return 0;
}
