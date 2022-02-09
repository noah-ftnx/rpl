#ifndef RPL_A_DP_TUF_TEST_DP14_H_
#define RPL_A_DP_TUF_TEST_DP14_H_

#include <iostream>
#include <iomanip>

bool prototype(vector<int> input, int k);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> input, int k, bool correct) {
  bool result = function(input, k);
  bool wrong = result !=correct;
  _wrong|=wrong;
  string s;
  for (auto i: input) s+=to_string(i) + " ";
  if (!s.empty()) s.pop_back();
  cout << setw(10) << s << ": " << boolalpha << result <<
      (wrong? " (WRONG)":"") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";
  test(function, {}, 7, false);
  test(function, {3, 4, 3}, 7, true);
  test(function, {3, 4, 3}, 8, false);
  test(function, {3, 5, 4, 11}, 11, true);
  test(function, {3, 5, 4, 11}, 15, true);
  cout << endl;
}

void print_errors() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
}


#endif  // RPL_A_DP_TUF_TEST_DP14_H_