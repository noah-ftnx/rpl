#include <vector>
using namespace std;

int countBF(long long nStairs);

int countMMZ(long long nStairs);

int countBU(long long nStairs);

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