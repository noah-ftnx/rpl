
void heapsort(vector<int> &vec);



#include "test/01-3.h"
int main() {
  run_tests(heapify, "heapify");
  run_tests(heapify, "heapifyInPlace");

  print_report();
  return 0;
}