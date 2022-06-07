#ifndef _H_
#define _H_

#include "../../../../.inc/base.h"
#include "../../../../.inc/vec.h"

void test(vector<int> input, vector<int> correct) {
  // string s;
  // stringstream ss;
  // for (auto i: vec) ss << setw(3) << to_string(i) << " ";

  // s=ss.str();
  // ss.str("");
  cout << setw(40) << to_string(input, 1);

  auto vec = input; // creating a copy
  heapify(vec); // in place

  cout << "  ->  ";
  cout << setw(40) << to_string(vec, 1);

  bool wrong = vec != correct;
  _wrong|=wrong;

  cout << "\t"  <<  (wrong? " (WRONG)": " correct") << endl;
}

void run_tests(string msg) {
  cout << msg  << ":\n";
  test({9, 25, 3, 10, 6, 4, 15, 2, 8, 40,24}, { 2, 6, 3, 8, 9, 4, 15, 10, 25, 40, 24} );
  test({25, 3, 10, 15, 2, 40}, {2, 3, 10, 15, 25, 40});

  cout << endl;
}

#endif  // _H_
