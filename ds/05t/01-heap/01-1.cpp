
void insert(vector<int> &vec, int val);

int pop(vector<int> &vec);

#include "test/01-1.h"
int main() {
  run_tests("insert then pop");

  print_report();
  return 0;
}
