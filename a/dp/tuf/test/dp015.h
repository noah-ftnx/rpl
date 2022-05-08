#ifndef RPL_A_DP_TUF_TEST_DP15_H_
#define RPL_A_DP_TUF_TEST_DP15_H_

#include <iostream>
#include <iomanip>

bool prototype(vector<int> &arr, int n);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> input, bool correct) {
  bool result = function(input, (int) input.size());
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
  // test(function, {},  true);
  test(function, {3, 4, 3}, false);
  test(function, {3, 5, 4, 12}, true);
  test(function, {2, 3, 3, 3, 4, 5}, true);
  test(function, {1,2,3,4,10}, true);
  test(function, {1,2,3,4,11}, false);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // RPL_A_DP_TUF_TEST_DP15_H_