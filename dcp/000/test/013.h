#ifndef RPL_DCP_TEST_013_H_
#define RPL_DCP_TEST_013_H_

#include <iostream>
#include <iomanip>

void test(string s, int k, int correct) {
  int result = longest_substring(s, k);

  cout << setw(10) << s  << ": unq: " << setw(3) << k << ":   " << result << (result!=correct? " (WRONG)":"") << endl;
}
void run_tests() {
  cout << "longest substring:\n";
  test("", 0, 0);
  test("a", 0, 0);
  test("ab", 1, 1);
  test("ab", 2, 2);
  test("ab", 3, 2);
  test("aa", 2, 2);
  test("aa", 1, 2);
  test("abc", 2, 2);
  test("abcba", 2, 3);
  test("abcba", 300, 5);
  test("abbbccdef", 2, 5);
  test("abbbccdef", 3, 6);
  test("abbbccddef", 3, 7);
}

#endif  // RPL_DCP_TEST_013_H_
