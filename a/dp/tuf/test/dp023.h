#ifndef RPL_A_DP_TUF_TEST_DP23_H_
#define RPL_A_DP_TUF_TEST_DP23_H_

#include <iostream>
#include <iomanip>

int prototype(int n, int w, vector<int> &profit, vector<int> &weight);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, int cap, vector<int> profit, vector<int> weight, int correct) {
  int result = function(profit.size(), cap, profit, weight);
  bool wrong = result !=correct;
  _wrong|=wrong;
  string s;
  for (int a: profit) s+=to_string(a) + " ";
  if (!s.empty()) s.pop_back(); else s="{}";
  cout << setw(10) << s;
  s.clear();
  for (int a: weight) s+=to_string(a) + " ";
  if (!s.empty()) s.pop_back(); else s="{}";
  cout << setw(10) << s;

  cout << ":\t Capacity: " << setw(2) << cap << " Profit: ";
  cout << setw(2) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  // test(function, nullptr,  0, 1, 0);
  test(function, 10, {15, 8}, {7, 4}, 16);
  test(function, 20, {15, 8}, {7, 4}, 40);
  test(function, 10, {5,11,13}, {2,4,6}, 27);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // RPL_A_DP_TUF_TEST_DP23_H_