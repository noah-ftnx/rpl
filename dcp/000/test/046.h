#ifndef RPL_DCP_000_TEST_046_H_
#define RPL_DCP_000_TEST_046_H_

#include <iostream>
#include <iomanip>

string prototype(string s);
using fptr = decltype(prototype);

bool _wrong {};

void test(fptr function, string input, string correct) {
  string res = function(input);
  bool wrong = (res!=correct) && (!(input=="na" && correct=="a" && res=="n"));
  _wrong|=wrong;

  cout << setw(10) << input << ": "
       << setw(10) << res
       << (wrong? " (WRONG)":"") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";
  test(function, "banana", "anana");
  test(function, "anna", "anna");
  test(function, "aabcdcb", "bcdcb");
  test(function, "na", "a");
  test(function, "n", "n");
  test(function, "", "");
  cout << endl;
}


void print_errors() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
}


#endif  // RPL_DCP_000_TEST_046_H_
