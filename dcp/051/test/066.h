#ifndef RPL_DCP_051_TEST_066_H_
#define RPL_DCP_051_TEST_066_H_

#include "base.h"

void test(int tosses) {
  int t{}, f{};
  for (int i=0; i<tosses; i++) {
    bool res = toss();
    if (res) t++; else f++;
  }

  double bias = t>f?  (double) t/f : (double) f/t;

  cout << "Tosses: " << setw(2) << tosses << " Heads: "  <<
      setw(2) << t << ". Tails: " << setw(2) << f << " Bias: " << setw(5) << bias << endl;
}

void run_tests() {
  // test(20);
  test(50);
  test(100);
}

#endif  // RPL_DCP_051_TEST_066_H_