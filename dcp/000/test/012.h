#ifndef RPL_DCP_TEST_012_H_
#define RPL_DCP_TEST_012_H_

#include <iostream>

int prototype(int N, vector<int> steps);
using fptr = decltype(prototype);


bool _wrong = false;

void test(fptr function, int n, vector<int> steps, int correct) {
  int res = function(n, steps);
  string ssteps;
  for (int s: steps) ssteps+=to_string(s) +", ";
  ssteps.pop_back();
  ssteps.pop_back();
  bool wrong = res != correct;
  _wrong |= wrong;
  cout << "stair: " << n << " steps: " << ssteps << ": ways: " <<  res << (wrong? " (WRONG)":"") << endl;
}


void test_function(string msg, fptr function) {
  cout << msg << ":" << endl;

  test(function, 0, {1,2}, 0);
  test(function,1, {1,2}, 1);
  test(function,2, {1,2}, 2);
  test(function,3, {1,2}, 3);
  test(function,3, {1,3}, 2);
  test(function,3, {1,2,3}, 4);
  test(function,4, {1,2}, 5);
  test(function,4, {2,4}, 2);
  test(function,4, {1,2,4}, 6);

  cout << endl;
}


#endif  // RPL_DCP_TEST_012_H_
