#include <vector>
using namespace std;

// IMPLEMENT: countBF
int countBF(long long nStairs);

// IMPLEMENT: countMMZ
int countMMZ(long long nStairs);

// IMPLEMENT: countBU
int countBU(long long nStairs);

// IMPLEMENT: countOPT
int countOPT(long long nStairs);



#include "test/dp002.h"
int main() {
  run_tests("BF", countBF);
  // run_tests("TD", countMMZ);
  // run_tests("BU", countBU);
  // run_tests("OPT", countOPT);

  print_errors();
  return 0;
}