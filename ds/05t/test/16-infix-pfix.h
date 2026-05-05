#ifndef RPL_DS_05T_TEST_16_INFIX_PFIX_H_
#define RPL_DS_05T_TEST_16_INFIX_PFIX_H_

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void check(string input, string correct) {
  string result = infix_to_postfix(input);
  bool wrong = result != correct;
  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(30) << input << setw(20) << result;
  if (wrong) cout << "Expected: " << correct;
  cout << endl;
}

void run_tests() {
  check("a+b+c", "ab+c+");
  check("a+b*c", "abc*+");
  check("a*(b+c)", "abc+*");
  check("a^b^c", "abc^^");
  check("a+b*3^5", "ab35^*+");
  check("(a+b)*c", "ab+c*");
  check("a*(b+c^d)-e/f", "abcd^+*ef/-");
  check("((a+b)*c)-(d-e)^(f+g)", "ab+c*de-fg+^-");
  cout << endl;
}

#endif  // RPL_DS_05T_TEST_16_INFIX_PFIX_H_
