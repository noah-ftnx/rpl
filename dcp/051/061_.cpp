double pow(int x, int y) {
  double base = x, exponent=y;
  // 3^2: 3*3
  if (y <0) {
    base=1/x;
    exponent= -y; // make it positive
  }

  double res=1;
  while (exponent--) {
    res*=base;
  }
  return res;
}


#include <cmath>
double pow_fast(int x, int y) {
  double base = x; int exponent=y;
  // 3^6: 6^2?
  // a^b = (a^2)^(b/2) if even..
  // a^b = a * (a^2)^((b-1)/2)
  if (y <0) {
    base=1/x;
    exponent=-y; // make it positive
  }

  if (y==0) return 1;

  double res = 1;
  while (exponent >1) {
    if (exponent%2==0) { // even
      base*=base; // square it
      exponent = exponent >> 1; // divide exponent
      // exponent /= 2;
    } else {
      res*=base;
      base*=base;
      // base*=base*base; // WRONG
      exponent=(exponent-1)>>1;
    }
  }

  return res*base;
}



#include "test/061.h"
int main() {
  run_tests("pow", pow);
  run_tests("pow_fast", pow_fast);
  return 0;
}