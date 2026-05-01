#ifndef RPL_A_STR_TEST_002_H_
#define RPL_A_STR_TEST_002_H_

#include <iostream>
#include <iomanip>

void test(string input, int correct) {
  int result = count_anagram_substrings(input);
  string label = input.empty() ? "\"\"" : input;

  cout << left << setw(10) << (label + ":")
       << setw(4) << result
       << (result == correct ? " [PASS]" : " [FAIL]") << endl;
}

void run_tests() {
  test("", 0);
  test("a", 1);
  test("ab", 3);
  test("aba", 4);
  test("aaa", 3);
  test("abba", 6);
  test("abcd", 10);
}

#endif  // RPL_A_STR_TEST_002_H_
