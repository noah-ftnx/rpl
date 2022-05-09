#ifndef RPL_A_DP_TUF_TEST_DP17_H_
#define RPL_A_DP_TUF_TEST_DP17_H_

#include <iostream>
#include <iomanip>

int prototype(vector<int> &num, int tar);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> input, int k, int correct) {
  int result = function(input, k);
  bool wrong = result !=correct;
  _wrong|=wrong;
  string s;
  for (auto i: input) s+=to_string(i) + " ";
  if (!s.empty()) s.pop_back(); else s="{}";
  cout << setw(15) << s << ": " << setw(6) << result
       << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";


  test(function, {},  1, 0);
  test(function, {3,4,3}, 6, 1);
  test(function, {1,3,2,3,3,4,5}, 6, 8);
  /* 8 ways:
   1,3,2 | 1,3,2 | 1,3,2
   1,5 | 2,4
   3,3 | 3,3 | 3,3
   */

  test(function, {1,2,2,3}, 3, 3);
  test(function, {0, 0, 1}, 1, 4);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // RPL_A_DP_TUF_TEST_DP17_H_