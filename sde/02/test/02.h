#ifndef _H_
#define _H_

#include "../../../.inc/base.h"
#include "../../../.inc/vec.h"

vector<vector<int>> prototype(vector<vector<int>>& intervals);
using fptr = decltype(prototype);

void test(fptr function, vector<vector<int>> vec, vector<vector<int>> correct) {

  auto res=function(vec);
  cout << setw(40) << to_string(vec) << " -> "; // BEF
  cout << setw(40) << to_string(res) << " "; // AFT

  bool wrong = correct!=res;
  _wrong|=wrong;

  cout << ":\t " << (wrong? " (WRONG)": " correct") << endl;
}



void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";

  test(function, {{1,3},{2,6},{8,10},{15,18}}, {{1,6},{8,10},{15,18}});
  test(function,{{1,3}}, {{1,3}});
  test(function, {}, {});
  test(function,{{1,3}, {4, 5}}, {{1,3}, {4,5}});
  test(function, {{1,7},{2,4},{5,8},{8,18}}, {{1,18}});

  cout << endl;
}

#endif  // _H_
