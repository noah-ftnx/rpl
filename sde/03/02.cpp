#include <cmath>
using namespace std;

double myPow(double x, int n);

#include "test/02.h"
int main() {
  run_tests("Sol", myPowBF);

  print_report();
  return 0;
}