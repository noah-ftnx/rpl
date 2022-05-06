#ifndef INC_070__CPP_A_DP_TUF_TEST_011_H_
#define INC_070__CPP_A_DP_TUF_TEST_011_H_

#include <iostream>
#include <iomanip>

int prototype(vector<vector<int>>& triangle, int n);
using fptr = decltype(prototype);

bool _wrong=false;
void test(fptr function, vector<vector<int>> triangle, int correct) {
  int result = function(triangle, (int) triangle.size());
  bool wrong = result != correct;
  _wrong|=wrong;
  // cout << endl;
  // for (auto row: triangle) {
  //   for (auto i: row) cout << i << " ";
  //   cout << endl;
  // }
  cout << "MIN SUM: " << result << (wrong? " (WRONG)": " correct.") << endl;
}


void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function,
       {{1},
        {2,3},
        {3,6,7},
        {8,9,6,10}}, 14);



  test(function,
       {{1},
        {2,1},
        {3,1,7},
        {8,9,1,10}}, 4);

  test(function,
       {{1},
        {2,1},
        {3,1,7},
        {8,50,50,2}}, 11);

  test(function,
       {{1}}, 1);




  cout << endl;
}

void print_errors() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect (all results).\n";
}

#endif  // INC_070__CPP_A_DP_TUF_TEST_011_H_