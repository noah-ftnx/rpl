#ifndef __H__
#define __H__

#include <iostream>
#include <iomanip>


int prototype(string s, string t);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, string s, string t, int correct) {
  int result = function(s, t);
  bool wrong = result !=correct;
  _wrong|=wrong;
  cout << setw(10) << (s.empty()?"{}":s) << ", " << setw(10) << (t.empty()?"{}":t) << " ";
  cout << "LCS: " << setw(2) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, "",  "", 0);
  test(function, "adebe", "dcadb", 3);
  test(function, "acd", "ced", 2);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // __H__