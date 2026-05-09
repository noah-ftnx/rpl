

// return pair of: <solutions, permutations>
// IMPLEMENT: n_queensBF
pair<int, int> n_queensBF(int N);


#include "test/nqueens_bf.h"
int main() {
  run_tests("BF", n_queensBF);
  return 0;
}