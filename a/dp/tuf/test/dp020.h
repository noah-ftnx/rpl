#ifndef RPL_A_DP_TUF_TEST_DP20_H_
#define RPL_A_DP_TUF_TEST_DP20_H_

#include <iostream>
#include <iomanip>

int prototype(vector<int> &num, int x);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> num, int x, int correct) {
  int result = function(num, x);
  bool wrong = result !=correct;
  _wrong|=wrong;
  string s;
  for (auto i: num) s+=to_string(i) + " ";
  if (!s.empty()) s.pop_back(); else s="{}";
  cout << setw(15) << s << ":\t Target: " << setw(2) << x << " Coins: ";
  cout << setw(2) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, {},  1, -1);
  test(function, {3},  5, -1);
  test(function, { 1, 2, 3, 4 }, 7, 2);
  test(function, { 1, 2 }, 7, 4);
  test(function, { 1, 2, 3 }, 7, 3);
  test(function, { 1, 6, 9 }, 12, 2);
  test(function, { 1 }, 7, 7);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // RPL_A_DP_TUF_TEST_DP20_H_