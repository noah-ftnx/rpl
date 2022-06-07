// INCLUDES here
#include <vector>
using namespace std;

#include "test/heap.h"



/*
 * @param input unsorted array
 */
MinHeap::MinHeap(const vector<int>& input) {
  for (auto i: input) vec.push_back(i);
  FloydHeapify();
}

MinHeap::~MinHeap() {
  vec.clear();
}

void MinHeap::FloydHeapify() { // TC is: O(n). It's NOT O(nlogn)
  // TRICKY could be from sz, BUT on leaf nodes it does nothing
  // and on a binary tree there are sz/2 non-leaf nodes. so ignore those.
  for (int i=(size()/2)-1; i>=0; --i) {
    percolade_down(i);
  }
}

int MinHeap::left(int node) {
  int p = (node*2) +1;
  return p >= size() ? -1 : p;
}

int MinHeap::right(int node) {
  int p = (node*2) +2;
  return p >= size() ? -1 : p;
}

int MinHeap::parent(int node) {
  return node==0? -1 : (node-1)/2;
}

// O(logn) for 1 item
void MinHeap::push(int v) {
  int idx = size();
  vec.resize(idx+1);

  vec[idx] = v;
  percolade_up(idx);
}

int MinHeap::top() { return vec[0]; }

void MinHeap::pop () {
  // get last value and remove it
  int last_val = vec[size()-1];
  vec.resize(size()-1);
  vec[0] = last_val;

  percolade_down(0);
}

void MinHeap::percolade_down(int idx) {
  while (true) {
    // assuming to continue on the left child (cidx)
    int cidx{left(idx)}, ridx{right(idx)};

    // NOTE there can't be a right node if left is empty (heap is a complete tree)
    if (cidx == -1) break;  // deleting a leaf.

    // will try on the right child
    if (ridx != -1 && vec[ridx] < vec[cidx]) cidx = ridx;

    if (vec[idx] < vec[cidx]) {  // arr is now heap
      break;
    } else {  // continue on the smallest child
      swap(vec[idx], vec[cidx]);
      idx = cidx;
    }
  }
}

void MinHeap::percolade_up(int idx) {
  int pidx;
  while ((pidx=parent(idx)) != -1) {
    if (vec[pidx] > vec[idx]) {
      swap(vec[pidx], vec[idx]);
    }
    idx=pidx; // move up
  }
}


#include "test/01.h"
int main() {
  run_tests("heapify");

  print_report();
  return 0;
}
