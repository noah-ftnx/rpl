#ifndef RPL_CHECK_CHECK_H_
#define RPL_CHECK_CHECK_H_

#include <string>
using namespace std;

void check_bool(string msg, bool result, bool correct) {
  cout << msg << ": " << boolalpha << result << (result != correct? " (WRONG)":"") << endl;
}

template <class T>
void check_result(string msg, T result, T correct) {
  cout << msg << ": " << to_string(result) << (result != correct? " (WRONG)":"") << endl;
}

#endif  // RPL_CHECK_CHECK_H_
