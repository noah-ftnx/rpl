#ifndef INC_070__CPP_DCP_051_TEST_075_H_
#define INC_070__CPP_DCP_051_TEST_075_H_

#include "base.h"

int prototype(vector<int> input);
using fptr = decltype(prototype);

void test(fptr function, string msg, vector<int> input, int correct) {
  int result = function(input);
  bool wrong = result != correct;
  _wrong|=wrong;
  cout << setw(10) << msg << ":  "  << result <<
      (wrong? " (WRONG)":"") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";
  test(function, "t1: ", {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}, 6);
  test(function, "t2: ", {0, 3, 4, 5, 10}, 5);
  test(function, "t2: ", {0, 3, 4, 5, 1}, 4);
  test(function, "t2: ", {10, 0, 3, 4, 5, 1}, 4);
  test(function, "t2: ", {10, 0, 3, 20, 4, 6, 5, 1}, 4);
  test(function, "t2: ", {10, 0, 3, 2, 20, 5, 4, 7, 5, 1, 6}, 5);
  cout << endl;
}

#endif  // INC_070__CPP_DCP_051_TEST_075_H_
