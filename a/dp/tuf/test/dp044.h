#ifndef __H__
#define __H__

#include <string>
#include <iostream>
#include <iomanip>

vector<int> prototype(vector<int> &arr);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> vec, vector<int> correct) {
  auto result = function(vec);

  bool wrong = result != correct;
  _wrong|=wrong;
  string s;
  for (int p: vec) s += to_string(p) + " ";
  cout << setw(25) << (s.empty()?"{}":s) << " ";
  s.clear();
  for (int p: result) s += to_string(p) + " ";

  cout << "\tLIS: " << setw(15) << s << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, {}, {});
  test(function, {10}, {10});
  test(function, {1, 16, 7, 8, 4}, {1, 4, 8, 16});
  test(function, {7, 1, 5, 3, 6, 4}, {1, 3, 6});
  test(function, {1, 10, 12, 4, 2, 3, 6, 7, 5}, {1,3,6,12});
  test(function, {1, 16, 8, 12, 4, 2, 3, 6, 7, 5}, {1,2,4,8,16});

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

void print_arrays(int N, vector<int>& nums,
                  vector<int> &dp, vector<int> &par) {
  cout << "  ";
  for (int i=0; i<N; i++) cout << nums[i] << " "; cout << endl;
  cout << "  ";
  for (int i=0; i<N; i++) cout << dp[i] << " "; cout << endl;
  for (int i=0; i<=N; i++) cout << par[i] << " "; cout << endl;
}

#endif  // __H__