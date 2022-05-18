#ifndef __H__
#define __H__

#include <string>
#include <iostream>
#include <iomanip>

int prototype(string str);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, string exp, int correct) {
  auto result = function(exp);

  bool wrong = result != correct;
  _wrong|=wrong;
  string s;
  cout << setw(25) << (exp.empty()?"{}":exp) << " ";

  cout << "\tCost: " << setw(15) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, "", 0);
  test(function, "abba", 0);
  test(function, "abbax", 1);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}



#endif  // __H__