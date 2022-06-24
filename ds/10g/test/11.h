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
  vector<vector<int>> matrix = { { INF, 10, 15, 20 },
                                 { 10, INF, 35, 25 },
                                 { 15, 35, INF, 30 },
                                 { 20, 25, 30, INF } };
  test(function, matrix, 80);
  return 0;
}


#endif  // _H_