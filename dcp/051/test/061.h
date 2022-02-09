#ifndef RPL_DCP_051_TEST_061_H_
#define RPL_DCP_051_TEST_061_H_

#include <iostream>
#include <iomanip>

bool _wrong {};

double prototype(int x, int y);
using fptr = decltype(prototype);

#include <cmath>
using std::cout;
using std::endl;
using std::setw;
using std::string;

void test(fptr function, int x, int y) {

  double result = function(x, y);
  double correct = std::pow(x, y);

  bool wrong = result!=correct;
  _wrong|=wrong;
  cout << setw(3) << x << ", "
       << setw(3) << y <<  ": "
  << result << (wrong?" (WRONG)":"") << endl;

}

void run_tests(string msg, fptr function) {
  cout << msg << ":" << endl;
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

  cout << endl <<  (_wrong?"WRONG RESULTS.": "Correct results.") << endl;
}

#endif  // RPL_DCP_051_TEST_061_H_
