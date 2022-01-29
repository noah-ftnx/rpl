#ifndef RPL_A_DP_TEST_G4G_DP28_H_
#define RPL_A_DP_TEST_G4G_DP28_H_

#include <iostream>
#include <iomanip>

// not the full solution. returns only min score
int prototype(string word);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, string s, int correct) {
  int result = function(s);
  bool wrong = result !=correct;
  _wrong|=wrong;
  cout << setw(10) << s << ": additions: "  << result <<
      (wrong? " (WRONG)":"") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";
  test(function, "ab", 1);
  test(function, "aa", 0);
  test(function, "", 0);
  test(function, "abcd", 3);
  test(function, "abcda", 2);
  test(function, "abcde", 4);
  test(function, "race", 3);
  test(function, "google", 2);
  cout << endl;
}

void print_errors() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
}

#endif  // RPL_A_DP_TEST_G4G_DP28_H_
