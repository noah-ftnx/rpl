
int n_queensBT(int N);

// using sets:
// int n_queensST(int N);



#include "test/038.h"
int main() {
  run_tests("BF", n_queensBT);
  // run_tests("ST", n_queensST);
  return 0;
}