#ifndef RPL_A_DP_TUF_TEST_DP14_H_
#define RPL_A_DP_TUF_TEST_DP14_H_

#include <iostream>
#include <iomanip>

bool prototype(int n, int k, vector<int> &arr);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> input, int k, bool correct) {
  bool result = function((int) input.size(), k, input);
  bool wrong = result !=correct;
  _wrong|=wrong;
  string s;
  for (auto i: input) s+=to_string(i) + " ";
  if (!s.empty()) s.pop_back(); else s="{}";
  cout << setw(15) << s << ": " << setw(6) << (result? "true":"false")
       << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
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

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // RPL_A_DP_TUF_TEST_DP14_H_