#ifndef RPL_DCP_TEST_031_H_
#define RPL_DCP_TEST_031_H_

#include <iostream>

int prototype(string a, string b);
using fptr = decltype(prototype);


bool _wrong = false;
void test(fptr function, string a, string b, int correct) {
  int result = function(a, b);
  bool wrong = correct!=result;
  _wrong|=wrong;
  cout << a << ", " << b << ": distance: " << result
       << (wrong? " (WRONG)":"") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";
  test(function, "kitten", "sitting", 3);
  test(function, "set", "be", 2);
  test(function, "Saturday", "Sundays", 4);
  test(function, "Saturday","Sunday", 3);
  test(function, "TomorrowIsSaturday","TomorrowIsSunday", 3);
  test(function, "TodayIsSaturday", "TomorrowIsSunday", 9);

  if (_wrong) cout << "\nWRONG RESULTS.\n";
}

#endif  // RPL_DCP_TEST_031_H_
