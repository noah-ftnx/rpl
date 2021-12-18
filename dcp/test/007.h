#ifndef RPL_DCP_TEST_007_H_
#define RPL_DCP_TEST_007_H_

#include <iostream>

int decodings(string str);

void check(string input, int correct) {
  int res = decodings(input);
  cout << input << ": " << res << (res!=correct?" (WRONG)":"") << endl;
}

void run_tests() {
  check("", 0);
  check("1", 1);
  check("9", 1);
  check("19", 2);
  check("26", 2);
  check("27", 1);
  check("1010", 1);

  check("111", 3);

  check("127", 2);
  check("126", 3);
  check("1026", 2);

  check("222", 3);
  check("2222", 4);
  check("22222", 5);

  check("1234", 3);
}

#endif  // RPL_DCP_TEST_007_H_
