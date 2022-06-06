#ifndef _H_
#define _H_

#include "../../../.inc/base.h"

double prototype(int n, long long m);
using fptr = decltype(prototype);

void test(fptr function, int n, long long m, double correct) {
  double res = function(n, m);

  double diff = abs(res-correct);
  bool wrong = diff>1e-6;
  _wrong|=wrong;

  cout  << setw(4) << n << "th root of: " << setw(4) << m << ": "
       << setprecision(7) << setw(10) << res << setw(10) << (wrong? " (WRONG)": " correct")
       << "\t diff: " << setw(10) << setprecision(8) << diff << endl;
}


void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";
  test(function, 2, 4, 2);
  test(function, 3, 8, 2);
  test(function, 4, 16, 2);
  test(function, 5, 32, 2);
  test(function, 3, 27, 3);

  cout << endl;
}

#endif  // _H_
