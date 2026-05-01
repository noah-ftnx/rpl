#ifndef RPL_DCP_TEST_025_H_
#define RPL_DCP_TEST_025_H_

#include <iostream>
#include <iomanip>

bool _wrong=false;

bool prototype(string input, string regex);
using fptr = decltype(prototype);

void test(fptr function, string word, string regex, bool correct) {
  bool result = function(word, regex);
  bool wrong = result != correct;
  _wrong|=wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << setw(15) << word << ": regex: " << setw(10) << regex << flush;

  cout << ": "  << boolalpha << result  << endl;
}

void test_method(fptr function) {
  test(function, "ray", "ra.", true);
  test(function, "raymont", "ra.", false);

  test(function, "chat", ".*at", true);

  test(function, "chats", ".*at", false);

  test(function, "cccccccccat", ".*at", true);

  test(function, "abc", "abc", true);
  test(function, "abc", "abc*", true);
  test(function, "abcccccc", "abc*", true);

  test(function, "cat", ".at", true);
  test(function, "kasjfkasjfkat", ".*at", true);
  test(function, "ataslfkdjaskfj", "at.*", true);
  test(function, "cat", ".*at", true);


  test(function, "abcxyz", "a.*z", true);
  test(function, "abbBbBcxyyYyYz", "a.*x.*z", true);
  test(function, "abbBbBcxyyYyYz", "a*x*e", false);


  test(function, "cccbaz", "c*b*az", true);
  test(function, "cccbbbaz", "c*b*az", true);
  test(function, "cbaz", "c*b*az", true);
  test(function, "az", "c*b*az", true);
  test(function, "bbbbaz", "c*b*az", true);
  test(function, "cccccaz", "c*b*az", true);
}


void run_tests(string msg, fptr function) {
  cout  << msg << ":\n";
  test_method(function);
  cout << endl;
}

void print_errors() {
  cout << (_wrong ? "[FAIL] " : "[PASS] ") << "\n"  << endl;
}

#endif  // RPL_DCP_TEST_025_H_
