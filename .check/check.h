#ifndef RPL_CHECK_CHECK_H_
#define RPL_CHECK_CHECK_H_

#include <string>
using namespace std;

void check_bool(string msg, bool result, bool correct_result) {
  cout << msg << ": " << boolalpha << result << (result != correct_result? " (WRONG)":"") << endl;
}

template <class T>
void check_result(string msg, T result, T correct_result) {
  cout << msg << ": " << result << (result != correct_result? " (WRONG)":"") << endl;
}

#endif  // RPL_CHECK_CHECK_H_
