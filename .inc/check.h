#ifndef RPL_CHECK_CHECK_H_
#define RPL_CHECK_CHECK_H_

#include <string>
#include <sstream>
#include <iostream>
#include <climits>

#include "to_string.h"

void check_bool(string msg, bool result, bool correct) {
  bool wrong = result != correct;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << msg << ": " << boolalpha << result;
  if (wrong) cout << " Expected: " << boolalpha << correct;
  cout << endl;
}


template <class T>
void check_result(string msg, T result, T correct) {
  bool wrong = result != correct;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << msg << ": " << to_string(result);
  if (wrong) cout << " Expected: " << to_string(correct);
  cout << endl;
}

// different classes
template <class A, class B>
bool check_result(A input, B result, B correct) {
  bool is_wrong=result!=correct;
  cout << (is_wrong ? "[FAIL] " : "[PASS] ") << to_string(input) << ":\t" << to_string(result);
  if (is_wrong) cout << " Expected: " << to_string(correct);
  cout << endl;
  return !is_wrong;
}

bool check_intPrettyMin(string msg, int result, int correct) {
  string pretty_int = (result==INT_MIN?"<nan>":to_string(result));
  bool wrong=result != correct;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << msg << ": " << pretty_int;
  if (wrong) cout << " Expected: " << to_string(correct);
  cout << endl;
  return wrong;
}

#endif  // RPL_CHECK_CHECK_H_
