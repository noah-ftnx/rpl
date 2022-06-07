// INCLUDES here
#include "test/heap.h"


/*
 * @param input unsorted array
 */
MinHeap::MinHeap(const vector<int>& input) {
}

MinHeap::~MinHeap() {
}

void MinHeap::heapsort();

// METHODS ARE MISSING
// Implement all required in order to support the below:
// then check on the names w/ the .h

void MinHeap::push(int v);
int MinHeap::top();
void MinHeap::pop ();


#include "test/01.h"
int main() {
  run_tests("heapify");

  print_report();
  return 0;
}
