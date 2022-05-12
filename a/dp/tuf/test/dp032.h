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

  test(function, "", "", 1);
  test(function, "brootgroot", "brt", 3);
  test(function, "babgbag", "bag", 5);
  test(function, "rabbbit", "rabbit", 3);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // __H__