#ifndef RPL_CHECK_CHECK_H_
#define RPL_CHECK_CHECK_H_

#include <string>
#include <sstream>
#include <iostream>
#include <climits>

#include "to_string.h"

void check_bool(string msg, bool result, bool correct) {
  cout << msg << ": " << boolalpha << result << (result != correct? " (WRONG)":"") << endl;
}



template <class T>
void check_result(string msg, T result, T correct) {
  cout << msg << ": " << to_string(result) << (result != correct? " (WRONG)":"") << endl;
}

// different classes
template <class A, class B>
void check_result(A input, B result, B correct) {
    cout << to_string(input) << ":\t"  << to_string(result) << (result != correct? " (WRONG)":"") << endl;
}

bool check_intPrettyMin(string msg, int result, int correct) {
  string pretty_int = (result==INT_MIN?"<nan>":to_string(result));
  bool wrong=result != correct;
  cout << msg << ": " << pretty_int << (wrong ? " (WRONG)":"") << endl;
  return wrong;
}

#endif  // RPL_CHECK_CHECK_H_
