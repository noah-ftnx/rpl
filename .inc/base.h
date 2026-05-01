#ifndef RPL_CHECK_BASE_H_
#define RPL_CHECK_BASE_H_

#include <iostream>
#include <iomanip>
using namespace std;

bool _wrong {};

void print_report() {
  cout << endl <<  (_wrong? "[FAIL]" : "[PASS]") << endl;
}

void print_errors() {
  if (_wrong) cout << "\n[FAIL]\n";
}


#endif  // RPL_CHECK_BASE_H_
