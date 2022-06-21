#ifndef RPL_CHECK_CHECK_H_
#define RPL_CHECK_CHECK_H_

#include <string>
#include <sstream>
#include <climits>

void check_bool(string msg, bool result, bool correct) {
  cout << msg << ": " << boolalpha << result << (result != correct? " (WRONG)":"") << endl;
}


string to_string(void* ptr) {
  stringstream ss;
  ss << "0x" << std::hex << reinterpret_cast<uintptr_t>(ptr);

  return ss.str();
}


template <class T>
void check_result(string msg, T result, T correct) {
  cout << msg << ": " << to_string(result) << (result != correct? " (WRONG)":"") << endl;
}

bool check_intPrettyMin(string msg, int result, int correct) {
  string pretty_int = (result==INT_MIN?"<nan>":to_string(result));
  bool wrong=result != correct;
  cout << msg << ": " << pretty_int << (wrong ? " (WRONG)":"") << endl;
  return wrong;
}

#endif  // RPL_CHECK_CHECK_H_
