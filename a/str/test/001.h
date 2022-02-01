#ifndef RPL_A_STR_TEST_001_H_
#define RPL_A_STR_TEST_001_H_

#include <iostream>
#include <iomanip>

bool _wrong {};

void test(string input, vector<string> correct) {
  auto res = substrings(input);

  cout << setw(3) << input << ": ";

  for (auto ss: res) cout << ss << " ";

  cout << (res != correct? " (WRONG)":"") << endl;
}

void run_tests() {
  test("ab", {"a", "ab", "b"});
  test("abc", {"a", "ab", "abc", "b", "bc", "c"});
}

#endif  // RPL_A_STR_TEST_001_H_
