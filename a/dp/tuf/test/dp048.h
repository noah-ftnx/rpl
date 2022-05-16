#ifndef __H__
#define __H__

#include <string>
#include <iostream>
#include <iomanip>

int prototype(vector<int> &arr, int N);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> vec, int correct) {
  auto result = function(vec, vec.size());

  bool wrong = result != correct;
  _wrong|=wrong;
  string s;
  for (auto v: vec) s += to_string(v) + " ";
  cout << setw(25) << (s.empty()?"{}":s) << " ";

  cout << "\tLIS: " << setw(15) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, {}, -1);

  test(function, {10}, -1);
  test(function, {10, 20}, 0);
  // test(function, { 10, 20, 30, 40, 50,}, 4);
  test(function, {1, 4, 3, 2}, 18);

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