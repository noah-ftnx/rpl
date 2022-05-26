#include <cmath>
using namespace std;

double myPowBF(double x, int n) {
  double res {1};
  for (int i=0; i<n; i++) res*=x;
  return res;
}

double myPowBF_NEG(double x, int n) {
  // no overflow protection
  // 8^{-1} is wrong
  double res {1};
  bool isNeg = n<0;
  n=abs(n);
  for (int i=0; i<n; i++) res*=x;
  return isNeg? (1/res) : res;
}

double myPowOPT(double base, int exponent) {
  double res {1}, tmp{1};

  while (exponent>1) {
    if (exponent % 2 != 0) { // odd exponent:
      // this if will run just once
      res=base;
      exponent--;
    }
    exponent=exponent/2;
    base*=base;
    tmp=base;
  }
  res*=tmp;

  return res;
}



double myPow_NEG(double base, int y) {
  long exponent=y;
  if (exponent==0) return 1;

  if (exponent <0) {
    base=1.0/base;
    exponent=abs(exponent); // OVERFLOW (ok as it's long)
  }

  double res {1};
  while (exponent>1) {
    if (exponent % 2 != 0) { // odd exponent:
      // this if will run just once
      res*=base;
      exponent--;
    }
    exponent=exponent/2;
    base*=base;
  }
  return res*base;
}



#include "test/02.h"
int main() {
  // run_tests("BF", myPowBF_NEG);
  run_tests("OPT-NEG", myPow_NEG);

  print_report();
  return 0;
}