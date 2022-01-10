#ifndef RPL_DCP_TEST_018_BONUS1_H_
#define RPL_DCP_TEST_018_BONUS1_H_

#include <iostream>

int prototype(int N);
using fptr = decltype(prototype);


// https://oeis.org/A000170
vector<int> _correct_results {1, 1, 0, 0, 2, 10, 4, 40, 92, 352,  724, 2680, 14200 }; // , 73712, 365596 (gets slow)

void test(fptr function, int N, int correct) {
  int solutions = function(N);

  cout << N << " Queens. Solutions: " << solutions
      << (solutions != correct ? " (WRONG)": "") << endl;
}


void run_tests(string msg, fptr function) {
  cout << msg << endl;
  for (int i=0; i<_correct_results.size(); i++) test(function, i, _correct_results[i]);
}

#endif  // RPL_DCP_TEST_018_BONUS1_H_