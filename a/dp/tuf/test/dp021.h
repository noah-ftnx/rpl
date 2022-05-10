#ifndef RPL_A_DP_TUF_TEST_DP21_H_
#define RPL_A_DP_TUF_TEST_DP21_H_

#include <iostream>
#include <iomanip>

int prototype(int n, int target, vector<int>& arr);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> num, int x, int correct) {
  int result = function(num.size(), x, num);
  bool wrong = result !=correct;
  _wrong|=wrong;
  string s;
  for (auto i: num) s+=to_string(i) + " ";
  if (!s.empty()) s.pop_back(); else s="{}";
  cout << setw(15) << s << ":\t Target: " << setw(2) << x << " Ways: ";
  cout << setw(2) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, {},  1, 0);
  test(function, {3},  5, 0);
  test(function, {10, 3, 4}, 3, 1);
  test(function, {1, 2, 3, 4}, 0, 2);
  test(function, {1, 2, 1, 3}, 3, 2);
  test(function, {1, 2, 1, 3, 0}, 3, 4);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // RPL_A_DP_TUF_TEST_DP21_H_