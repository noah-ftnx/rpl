#ifndef RPL_DCP_TEST_029_H_
#define RPL_DCP_TEST_029_H_

#include <iostream>

void test(string input, string correct) {
  string result = encode(input);

  cout << input << ": "<< result <<
      (result!=correct? " (WRONG)":"") << endl;
}

void run_tests() {
  test("AAAABBBCCDAA", "4A3B2C1D2A");
  test("", "");
  test("A", "1A");
  test("AAAAA", "5A");
  test("ABBB", "1A3B");
}

#endif  // RPL_DCP_TEST_029_H_
