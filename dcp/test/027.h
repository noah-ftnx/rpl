#ifndef RPL_DCP_TEST_027_H_
#define RPL_DCP_TEST_027_H_

#include <iostream>
#include <iomanip>

void test(string input, bool correct) {
  bool result = match_parenthesis(input);

  cout << setw(10) << input << ": " << boolalpha << result
       << (result!=correct? " (WRONG)":"") << endl;
}

void run_tests() {
  test("([])[]({})", true);
  test("([)]", false);
  test("((()", false);
  test("", true);
}

#endif  // RPL_DCP_TEST_027_H_
