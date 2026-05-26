#ifndef _H_
#define _H_

#include "../../../.inc/base.h"
#include "../../../.inc/to_string.h"


bool prototype(vector<vector<int>>& matrix, int target);
using fptr = decltype(prototype);

void test(fptr function, vector<vector<int>> vec, int tgt, bool correct) {

  auto res = function(vec, tgt);

  bool wrong = res!=correct;
  _wrong|=wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ") << setw(3)  << tgt << ": " << (res?"T":"F")  << endl;
}


void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";


  vector<vector<int>> vec2 {{1,3,5,7},
                            {10,11,16,20},
                            {23,30,34,60}};

  cout << endl << setw(20) << to_string(vec2, false, 2) << "\n\n";

  test(function, vec2, 13, false);
  test(function, vec2, 34, true);
  test(function, vec2, 30, true);
  test(function, vec2, 2, false);
  test(function, vec2, 1, true);
  test(function, vec2, 23, true);
  test(function, vec2, 60, true);
  test(function, vec2, 61, false);

  vector<vector<int>> one {{5}};
  test(function, one, 5, true);
  test(function, one, 4, false);

  vector<vector<int>> one_row {{1, 3, 5, 7}};
  test(function, one_row, 7, true);
  test(function, one_row, 6, false);

  vector<vector<int>> one_col {{1}, {3}, {5}, {7}};
  test(function, one_col, 7, true);
  test(function, one_col, 2, false);

  vector<vector<int>> empty;
  test(function, empty, 1, false);

  vector<vector<int>> empty_row {{}};
  test(function, empty_row, 1, false);


  cout << endl;
}

#endif  // _H_
