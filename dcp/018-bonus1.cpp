#include <vector>
using namespace std;

int n_queensBT(int N);

// int n_queensST(int N);



#include "test/018-bonus1.h"
int main() {
  run_tests("BF", n_queensBT);
  // run_tests("ST", n_queensST);
  return 0;
}