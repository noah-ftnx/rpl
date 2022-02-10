#ifndef RPL_DCP_051_TEST_065_H_
#define RPL_DCP_051_TEST_065_H_

#include "base.h"

void test(vector<vector<int>> input, string correct) {
  string result = clockwise_spiral(input);
  result.pop_back();
  bool wrong = result!=correct;
  _wrong|=wrong;
  cout << "Spiral: " << result << ". " << (wrong? " (WRONG)": "Correct.") << endl;
}

void run_tests() {
  test({{1,  2,  3,  4,  5},
        {6,  7,  8,  9,  10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}},
       "1 2 3 4 5 10 15 20 19 18 17 16 11 6 7 8 9 14 13 12");
}

#endif  // RPL_DCP_051_TEST_065_H_
