///////////////////////////////////////////////////////////////////////////////////////////////////
// NORMAL:
// HEADER
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "base.h"

void test(T input, T correct) {
  T result = CALL();
  bool wrong = result!=correct;
  _wrong|=wrong;
  cout << n << "x" << m << ": " << result
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

#include "base.h"

int prototype(T param0);
using fptr = decltype(prototype);

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


// C++
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "test/004.h"
int main() {
  run_tests("BF", fBF);
  run_tests("MMZ", fMMZ);
  run_tests("BU", fBU);
  run_tests("OPT", fOPT);

  // print_errors();
  // print_report();
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
