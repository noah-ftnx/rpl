#ifndef RPL_A_STR_TEST_002V1_H_
#define RPL_A_STR_TEST_002V1_H_

#include <iostream>
#include <iomanip>

void test(string input, int correct) {
  int result = count_anagram_reorderings(input);
  string label = input.empty() ? "\"\"" : input;

  cout << left << setw(8) << (label + ":")
       << setw(4) << result
       << (result == correct ? " [PASS]" : " ([FAIL] Expected: " + to_string(correct) + ")")
       << endl;
}

void run_tests() {
  test("", 0);
  test("a", 1);
  test("ab", 4);
  test("aba", 7);
  test("aaa", 3);
  test("abb", 8);
  test("abc", 13);
}

#endif  // RPL_A_STR_TEST_002V1_H_
