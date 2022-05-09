#ifndef RPL_A_DP_TUF_TEST_DP18_H_
#define RPL_A_DP_TUF_TEST_DP18_H_

#include <iostream>
#include <iomanip>

int prototype(int n, int d, vector<int> &arr);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> input, int d, int correct) {
  int result = function(input.size(), d, input);
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
  test(function, {1,2, 5}, 2, 1);
  test(function, {5, 2, 6, 4}, 3, 1);
  test(function, {1,1,1,1}, 0, 6);

  test(function, {1, 4, 5}, 0, 2);
  test(function, {1, 4, 6}, 1, 1);


  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // RPL_A_DP_TUF_TEST_DP18_H_