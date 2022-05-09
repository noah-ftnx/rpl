#ifndef RPL_A_DP_TUF_TEST_DP19_H_
#define RPL_A_DP_TUF_TEST_DP19_H_

#include <iostream>
#include <iomanip>

int prototype(vector<int> weight, vector<int> value, int n, int maxWeight);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> in1, vector<int> in2, int capacity, int correct) {
  int result = function(in1, in2, in1.size(), capacity);
  bool wrong = result !=correct;
  _wrong|=wrong;
  string s;
  for (auto i: in1) s+=to_string(i) + " ";
  if (!s.empty()) s.pop_back(); else s="{}";
  cout << setw(20) << s << ": ";
  s.clear();
  for (auto i: in2) s+=to_string(i) + " ";
  if (!s.empty()) s.pop_back(); else s="{}";
  cout << setw(20) << s << ": Weight: " << setw(3) << capacity;
  cout << setw(6) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  // test(function, {},  1, 0);
  test(function, {2,4,3}, {20,40,30}, 5, 50);
  test(function, {1, 2, 4, 5}, {5, 4, 8, 6}, 5, 13);
  test(function, {4,2,4}, {80,100,100}, 10, 280);
  test(function, {3,2,4,3,2,4}, {30,50,80,50,100,100}, 10, 280);
  test(function, {4,2,3,3,2,4}, {80,50,30,50,100,100}, 10, 280);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // RPL_A_DP_TUF_TEST_DP19_H_