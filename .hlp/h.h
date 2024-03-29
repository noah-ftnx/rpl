//////////////////
// 1. CREATE A /best/base.h file
//////////////////
#ifndef _BASE_
#define _BASE_

#include "../../../.inc/base.h"

#endif  // _BASE_


//////////////////
// 2. INCLUDE THE BASE FILE & write tests
//////////////////

#include "base.h"

void test(T input, T correct) {
  T result = CALL();
  bool wrong = result!=correct;
  _wrong|=wrong;
  cout << "MSG: "<< result
       << (wrong? " (WRONG)": "") << endl;
}

void run_tests() {

}

// C++
///////////////////////////////////////////////////////////////////////////////////////////////////
#include "test/05x.h"
int main() { run_tests(); return 0; }


///////////////////////////////////////////////////////////////////////////////////////////////////
// DYNAMIC PROGRAMMING:
///////////////////////////////////////////////////////////////////////////////////////////////////
// HEADER
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
// #include "base.h"

int prototype(T param0);
using fptr = decltype(prototype);

bool _wrong {};

void test(fptr function, string s, T correct) {
  // T result = function(s);
  bool wrong = result !=correct;
  _wrong|=wrong;
  cout << setw(10) << s << ": MSG: "  << result <<
      (wrong? " (WRONG)":"") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";
  test(function, "ab", 1);
  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}


// C++
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "test/075.h"
int main() {
  run_tests("BF", fBF);
  run_tests("MMZ", fMMZ);
  run_tests("BU", fBU);
  run_tests("OPT", fOPT);

  print_errors();
  // print_report();
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
