#ifndef __H__
#define __H__

#include <iostream>
#include <iomanip>

int prototype(string &s);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, string s, int correct) {
  int result = function(s);
  bool wrong = result !=correct;
  _wrong|=wrong;
  cout << setw(20) << (s.empty()?"{}":s) << " ";
  cout << "Min: " << setw(5) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, "", 0);
  test(function, "ab", 1);
  test(function, "aa", 0);
  test(function, "abcd", 3);
  test(function, "abcda", 2);
  test(function, "abcde", 4);
  test(function, "race", 3);
  test(function, "google", 2);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // __H__