#ifndef _H_
#define _H_

#include "../../../.inc/base.h"
// #include "../../../.inc/vec.h"


double prototype(double base, int exponent);
using fptr = decltype(prototype);

void test(fptr function, int x, int y) {

  auto res = function(x, y);
  double correct = std::pow(x, y);

  bool wrong = res!=correct;
  _wrong|=wrong;

   cout << setw(3) << x << ", "
        << setw(3) << y <<  ": "
        << (wrong? " (WRONG)": " correct") << endl;

}


void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";

  test(function, 2, 0);
  test(function, 0, 0);

  test(function, 2, 3);
  test(function, 2, 5);
  test(function, 2, 4);

  test(function, 2, -5);
  test(function, 2, -4);


  test(function, 3, 33);
  test(function, 3, 32);
  cout << endl;


  cout << endl;
}

#endif  // _H_
