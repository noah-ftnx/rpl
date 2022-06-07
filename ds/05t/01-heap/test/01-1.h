#ifndef _H_
#define _H_

#include "../../../../.inc/base.h"
#include "../../../../.inc/vec.h"

void test(vector<int> input, int insertVal, int correctPopVal, vector<int> correctOp1, vector<int> correctOp2) {
  cout << "1. Insert: " << insertVal << endl;
  auto vec = input;
  insert(vec, insertVal);
  cout << to_string(vec, 1) << endl;
  bool wrong = vec != correctOp1;

  auto popVal = pop(vec);
  cout << "\n2. Pop: " << popVal << endl;
  wrong |= popVal != correctPopVal;
  wrong |= vec != correctOp2;
  _wrong|=wrong;

  cout << to_string(vec, 1) << endl;

  cout << "\nResult: "  <<  (wrong? " (WRONG)": " correct") << endl;
}

void run_tests(string msg) {
  cout << msg  << ":\n";
  test({2, 6, 3, 8, 9, 4, 15, 10, 25, 40, 24}, 39, 2,
       {2, 6, 3, 8, 9, 4, 15, 10, 25, 40, 24, 39},
       {3, 6, 4, 8, 9, 39, 15, 10, 25, 40, 24}
 );

  cout << endl;
}

#endif  // _H_
