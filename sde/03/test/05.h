#ifndef _H_
#define _H_

#include "../../../.inc/base.h"

int prototype(int m, int n);
using fptr = decltype(prototype);

void test(fptr function, int m, int n, int correct) {
  int res=function(m, n);
  bool wrong=res!=correct;
  _wrong|=wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << "m=" << setw(2) << m << " n=" << setw(2) << n;
  cout << " -> " << setw(4) << res;
  if (wrong) cout << " (WRONG. Expected: " << correct << ")";
  cout << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, 3, 7, 28);
  test(function, 3, 2, 3);
  test(function, 1, 1, 1);
  test(function, 1, 5, 1);
  test(function, 5, 1, 1);
  test(function, 3, 3, 6);
  test(function, 10, 10, 48620);

  cout << endl;
}

#endif  // _H_
