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
  cout << setw(15) << (s.empty()?"{}":s) << " ";
  cout << setw(15) << (s.empty()?"{}":t) << " ";
  cout << "Sum: " << setw(5) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, "", "", 0);
  test(function, "abc", "XXabc", 2);
  test(function, "abc", "abcXX", 2);
  test(function, "XXabc", "abc", 2);
  test(function, "abcXX", "abc", 2);
  test(function, "abc", "XXabcXX", 4);
  test(function, "horse", "ros", 3);
  // horse -> rorse (replace 'h' with 'r')
  // rorse -> rose (remove 'r')
  // rose -> ros (remove 'e')

  test(function, "kitten", "sitting", 3);
  test(function, "set", "be", 2);
  test(function, "Saturday", "Sundays", 4);
  test(function, "Saturday","Sunday", 3);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // __H__