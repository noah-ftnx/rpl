#ifndef _H_
#define _H_

#include "../../../.inc/base.h"
// #include "../../../.inc/vec.h"


double prototype(double base, int exponent);
using fptr = decltype(prototype);

void test(fptr function, double  x, int y) {

  auto res = function(x, y);
  double correct = std::pow(x, y);

  bool wrong = (abs(res-correct)>=1);
  _wrong|=wrong;

   cout << setw(13) << x << " "
        << setw(13) << y <<  ": "
       << setw(15) << res << " : C: "
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

  test(function, 1.72777, 7);
  test(function, 2.00000, -2147483648);



  cout << endl;
  cout << endl;
}

#endif  // _H_
