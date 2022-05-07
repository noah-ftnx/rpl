#ifndef INC_070__CPP_A_DP_TUF_TEST_013_H_
#define INC_070__CPP_A_DP_TUF_TEST_013_H_

#include <iostream>
#include <iomanip>

int prototype(int r, int c, vector<vector<int>> &grid) ;
using fptr = decltype(prototype);

bool _wrong=false;
void test(fptr function, vector<vector<int>> in1, int correct) {
  const int in2=(int)in1.size();
  const int in3=(int)in1[0].size();
  int result = function(in2, in3, in1);
  bool wrong = result != correct;
  _wrong|=wrong;
  cout << "max chocolates: " << result << (wrong? " (WRONG)": " correct.") << endl;
}


void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function,
       {{1,0,0,1},
        {10,3,20,1},
        {4,1,20,1},
        {1,10,10,1}}, 76);

  test(function,
       {{1,0,1},
        {10,20,1},
        {4,20,1},
        {1,10,1}}, 67);

  test(function,
       {{1, 20, 15}}, 16);

  test(function,
       {{1}}, 1);


  cout << endl;
}

void print_errors() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect (all results).\n";
}

#endif  // INC_070__CPP_A_DP_TUF_TEST_013_H_