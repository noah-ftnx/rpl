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
  percolade_up(idx);
}

int MinHeap::top() { return vec[0]; }

void MinHeap::pop() {
  // remove the top:
  // copy last element to top, decreas size.
  // percolate top down

  int last = vec[size()-1];
  vec.resize(size()-1);

  vec[0]=last;
  percolade_down(0);
}


int MinHeap::left (int idx) {
  int ch = (2*idx)+1;
  return ch<size()? ch: -1;
}

int MinHeap::right(int idx) {
  int ch = (2*idx)+2;
  return ch<size()? ch: -1;
}

int MinHeap::parent(int idx) {
  return idx==0? -1 : (idx-1)/2;
}

void MinHeap::percolade_down(int idx) {
  // greater than left or right
  bool gtL=true, gtR=true;
  while(gtL || gtR) { // it's greater than child, move down
    int L = left(idx);
    int R = right(idx);
    gtL = L>=0 && vec[idx] > vec[L];
    gtR = R>=0 && vec[idx] > vec[R];

    // greater than both and L is smaller, or gtL
    if ((gtL && gtL && vec[L] < vec[R]) || gtL) {
      swap(vec[idx], vec[L]);
      idx=L;
    } else if (gtR) {
      swap(vec[idx],vec[R]);
      idx=R;
    }
  }
}

void MinHeap::percolade_up(int idx) {
  while (parent(idx)>=0) {
    if (vec[idx] < vec[parent(idx)]) {
      swap(vec[idx], vec[parent(idx)]);
      vec=parent(idx);
    } else break;
  }
}

#include "test/01.h"
int main() {
  run_tests("heapify");

  print_report();
  return 0;
}
