#ifndef __H__
#define __H__

#include <string>
#include <iostream>
#include <iomanip>

int prototype(vector<int> &arr);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> vec, int correct) {
  auto result = function(vec);

  bool wrong = result != correct;
  _wrong|=wrong;
  string s;
  for (auto v: vec) s += to_string(v) + " ";
  cout << setw(25) << (s.empty()?"{}":s) << " ";

  cout << "\tLIS: " << setw(15) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, {}, 0);

  test(function, { 1,5,4,3,2,6,7,10,8,9}, 4);

  test(function, {50, 3, 90, 60, 80}, 2);
  test(function, {3, 7, 4, 6}, 1);

  // 2 ways to build size 2: 5,7, and 2,3
  // at the end there is a loop to sum all up
  test(function, {5, 7, 2, 3}, 2);
  test(function, {4, 4, 4}, 3);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

void print_verification(vector<int> &arr, vector<int> &dp, vector<int> &ways) {
  const int N = (int) arr.size();
  cout << "  arr: ";
  for (int i=0; i<N; i++) cout << setw(2) << arr[i] << " "; cout << endl;
  cout << "   dp: ";
  for (int i=0; i<N; i++) cout << setw(2) << dp[i] << " "; cout << endl;
  cout << " ways: ";
  for (int i=0; i<N; i++) cout << setw(2) << ways[i] << " "; cout << endl;
}


#endif  // __H__