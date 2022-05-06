#ifndef INC_070__CPP_A_DP_TUF_TEST_012_H_
#define INC_070__CPP_A_DP_TUF_TEST_012_H_

#include <iostream>
#include <iomanip>

int prototype(vector<vector<int>> &matrix);
using fptr = decltype(prototype);

bool _wrong=false;
void test(fptr function, vector<vector<int>> in1, int correct) {
  int result = function(in1);
  bool wrong = result != correct;
  _wrong|=wrong;
  cout << "max sum: " << result << (wrong? " (WRONG)": " correct.") << endl;
}


void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function,
       {{1,2,10,4},
        {100,3,2,1},
        {1,1,20,1},
        {1,2,2,1}}, 105);

  test(function,
       {{1,2,10,4},
        {100,3,2,1},
        {1,1,200,1},
        {1,2,2,1}}, 215);

  test(function,
       {{1}}, 1);

  test(function,
       {{1, 20, 15}}, 20);


  cout << endl;
}

void print_errors() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect (all results).\n";
}

#endif  // INC_070__CPP_A_DP_TUF_TEST_012_H_