#ifndef RPL_CHECK_CHECK_OPT_H_
#define RPL_CHECK_CHECK_OPT_H_

#include <string>
using namespace std;

template <class T>
void check_optional(string msg, optional<T> result, optional<T> correct) {
  cout << msg << ": " << (result? to_string(result.value()): "<nullopt>")
       << (result!=correct?" (WRONG)": "") << endl;
}

#endif  // RPL_CHECK_CHECK_OPT_H_
