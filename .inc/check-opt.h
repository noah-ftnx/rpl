#ifndef RPL_CHECK_CHECK_OPT_H_
#define RPL_CHECK_CHECK_OPT_H_

#include <string>
using namespace std;

template <class T>
void check_optional(string msg, optional<T> result, optional<T> correct) {
  bool wrong = result != correct;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << msg << ": "
       << (result? to_string(result.value()): "<nullopt>");
  if (wrong) cout << " Expected: " << (correct ? to_string(correct.value()) : "<nullopt>");
  cout << endl;
}

#endif  // RPL_CHECK_CHECK_OPT_H_
