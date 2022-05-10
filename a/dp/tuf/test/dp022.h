#ifndef RPL_A_DP_TUF_TEST_DP22_H_
#define RPL_A_DP_TUF_TEST_DP22_H_

#include <iostream>
#include <iomanip>

long prototype(int *arr, int n, int value);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, int* arr, int n, int value, int correct) {
  int result = function(arr, n, value);
  bool wrong = result !=correct;
  _wrong|=wrong;
  string s;
  for (int i=0; i<n; i++) s+=to_string(arr[i]) + " ";
  if (!s.empty()) s.pop_back(); else s="{}";
  cout << setw(15) << s << ":\t Target: " << setw(2) << value << " Ways: ";
  cout << setw(2) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, nullptr,  0, 1, 0);

  int t1[1] {3};
  test(function, t1, 1, 3, 1);
  int t2[3] {1,2,3};
  test(function, t2, 3, 3, 3);
  test(function, t2, 3, 4, 4);
  // 7x1
  // 2+5x1
  // 2x2+3x1
  // 2x2+1x3
  // 3+4x1
  // 2x3+1x1
  // 2x2+1x3
  // 1x2+1x3+2x1
  test(function, t2, 3, 7, 8);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // RPL_A_DP_TUF_TEST_DP22_H_