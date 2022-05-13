#ifndef __H__
#define __H__

#include <iostream>
#include <iomanip>

bool prototype(string pattern, string text);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, string s, string t, int correct) {
  int result = function(s, t);
  bool wrong = result !=correct;
  _wrong|=wrong;
  cout << setw(15) << (s.empty()?"{}":s) << " ";
  cout << setw(15) << (s.empty()?"{}":t) << " ";
  cout << "\tMatch: " << setw(2) << (result?"T":"F") << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, "", "", true);
  test(function, "?ay", "ray", true);
  test(function, "*", "abc", true);
  test(function, "*y", "ay", true);
  test(function, "*y", "ABCABCABCABCy", true);
  test(function, "ab*cd", "abdefcd", true);
  test(function, "ab?d", "abcc", false);
  test(function, "ab*", "abABCABCABCABC", true);
  test(function, "ab*", "ab", true);
  test(function, "ab?", "ab", false);
  test(function, "ab*cd*xz", "abFFFFcdxz", true);
  test(function, "ab*cd*xz", "abFFFFcdzz", false);
  test(function, "ab*cd*?z", "abFFFFcdzz", true);
  test(function, "**z", "ABCABCABCz", true);
  test(function, "**z***", "ABCABCABCz", true);
  test(function, "**z***", "ABCABCABCzWWWWW", true);
  test(function, "*", "", true);
  test(function, "***", "", true);



  test(function, "ab*xz", "ababxxababxxxz", true);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // __H__