#ifndef _H_
#define _H_

#include "../../../.inc/base.h"

int prototype(string s);
using fptr = decltype(prototype);

void test(fptr function, string input, int correct) {
  int res = function(input);
  bool wrong = res != correct;
  _wrong |= wrong;
  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << setw(20) << input << " : " << setw(3) << res;
  if (wrong) cout << " (WRONG. Expected: " << correct << ")";
  cout << endl;
}

void run_tests(fptr function, string msg) {
  cout << msg << ":\n";
  test(function, "", 0);
  test(function, "abcabcbb", 3);
  test(function, "bbbbb", 1);
  test(function, "pwwkew", 3);
  test(function, "dvdf", 3);
  test(function, "abba", 2);
  test(function, "tmmzuxt", 5);
  cout << endl;
}

#endif  // _H_
