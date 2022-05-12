#ifndef __H__
#define __H__

#include <iostream>
#include <iomanip>

string prototype(string a, string b);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, string s, string t, string correct) {
  string result = function(s, t);
  bool wrong = result !=correct;
  _wrong|=wrong;
  cout << setw(20) << (s.empty()?"{}":s) << " ";
  cout << setw(20) << (s.empty()?"{}":t) << " ";
  cout << "Min: " << setw(20) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, "", "", "");
  test(function, "bleed", "blue", "bleued");
  test(function, "broot","groot", "bgroot");
  test(function, "abc", "abc", "abc");
  test(function, "str", "ptr", "sptr");

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // __H__