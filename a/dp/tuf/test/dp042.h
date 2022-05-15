#ifndef __H__
#define __H__

#include <string>
#include <iostream>
#include <iomanip>

string prototype(vector<int>& nums);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> vec, string c1, string c2="") {
  string result = function(vec);

  // remove first or last space
  if (!result.empty()) {
    if (result[0]==' ') {
      result.erase(0, 1);
    } else if (result[result.size()-1]==' ') {
      result.pop_back();
    }
  }

  bool t1= result !=c1;
  bool t2= result !=c2;
  bool wrong = (!t1 && !t2);
  _wrong|=wrong;
  string s;
  for (int p: vec) s += to_string(p) + " ";
  cout << setw(25) << (s.empty()?"{}":s) << " ";
  cout << "\tLIS: " << setw(15) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  // test(function, {}, "", " ");
  // test(function, {10}, "10");
  // test(function, {8, 8, 8}, "8");
  // test(function, {7, 1, 5, 3, 6, 4}, "1 5 6", "1 3 4");
  // test(function, {7, 1, 5, 3, 6, 4, 5}, "1 3 4 5");
  test(function, {1, 10, 11, 4, 2, 3, 5, 5, 6, 7, 5}, "1 2 3 5 6 7");
  // test(function, {10, 9, 2, 5, 3, 7, 101, 18}, "2 5 7 101");

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