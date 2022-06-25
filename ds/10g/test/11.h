#ifndef _H_
#define _H_

#include <iomanip>
#include "../../../.inc/base.h"
#include "../../../.inc/vec.h"

int prototype(vector<vector<int>> CostGraphMatrix);
using fptr = decltype(prototype);

void test(fptr function, const vector<vector<int>> matrix, int correct) {
  int result=function(matrix);

  bool wrong = result!=correct;
  _wrong|=wrong;

  cout << "Cost: " << result <<  (wrong? " (WRONG)": " correct") << endl;
}

// Driver code
int run_tests(fptr function){
  vector<vector<int>> m1 = { { INF, 10, 15, 20 },
                             { 10, INF, 35, 25 },
                             { 15, 35, INF, 30 },
                             { 20, 25, 30, INF } };
  test(function, m1, 80);

  vector<vector<int>> m2 = { {INF, 4, INF, 2, 1 },
                             { 4, INF, 2, 1, INF },
                             { INF, 2, INF, 3, 9 },
                             { 1, INF, 9, 1, INF } };
  test(function, m2, 10);

  return 0;
}

#endif  // _H_