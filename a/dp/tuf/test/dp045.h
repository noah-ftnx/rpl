#ifndef __H__
#define __H__

#include <string>
#include <iostream>
#include <iomanip>

int prototype(vector<string> &arr);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<string> vec, int correct) {
  auto result = function(vec);

  bool wrong = result != correct;
  _wrong|=wrong;
  string s;
  for (auto v: vec) s += v + " ";
  cout << setw(25) << (s.empty()?"{}":s) << " ";

  cout << "\tLIS: " << setw(15) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, {}, {});
  test(function, {"a", "b", "ba", "bca", "bda","bdca"}, 4);  // "a",  "ba", "bca","bdca"
  test(function, {"ba", "a",  "bdca", "ba", "bca", "b", "bda"}, 4);  // "a",  "ba", "bca","bdca"
  test(function, {"x", "xx", "y", "xyx"}, 3); // “x” -> “xx” -> “xyx”
  test(function, {"x", "xx", "y", "xyx", "www", "xyxww"}, 3); // “x” -> “xx” -> “xyx”

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