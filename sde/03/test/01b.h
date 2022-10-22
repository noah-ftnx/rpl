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

  cout << setw(3) << tgt << ": " << (res?"T":"F") << (wrong? " (WRONG)": " correct") << endl;
}


void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";

  vector<vector<int>> vec1 {{10, 20, 30, 40},
                            {11, 21, 36, 43},
                            {25, 29, 39, 50},
                            {50, 60, 70, 80}};


  cout << setw(20) << to_string(vec1, false, 2) << "\n\n";

  test(function, vec1, 29, true);
  test(function, vec1, 25, true);
  test(function, vec1, 11, true);
  test(function, vec1, 10, true);
  test(function, vec1, 40, true);
  test(function, vec1, 9, false);
  test(function, vec1, 61, false);
  test(function, vec1, 38, false);

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


  cout << endl;
}

#endif  // _H_
