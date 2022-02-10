#ifndef RPL_CHECK_BASE_H_
#define RPL_CHECK_BASE_H_

#include <iostream>
#include <iomanip>

bool _wrong {};

void print_report() {
  cout << endl <<  (_wrong? "WRONG RESULTS." : "Correct (all tests)") << endl;
}

void print_errors() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
}


#endif  // RPL_CHECK_BASE_H_
