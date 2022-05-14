#ifndef __H__
#define __H__

#include <string>
#include <iostream>
#include <iomanip>

int prototype(int fee, vector<int> &prices);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> prices, int fee, int correct) {
  int result = function(fee, prices);
  bool wrong = result !=correct;
  _wrong|=wrong;
  string s;
  for (int p: prices) s += to_string(p) + " ";
  cout << "Fee:" << setw(2) << fee << setw(20) << (s.empty()?"{}":s) << " ";
  cout << "\tProfit: " << setw(3) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, {}, 0, 0);
  test(function, {10}, 0, 0);
  test(function,{7, 1, 5, 3, 6, 4}, 0, 7);
  test(function,{7, 1, 5, 3, 7, 4}, 0, 8);

  test(function,{7, 1, 5, 3, 6, 4}, 2, 3);
  test(function,{7, 1, 5, 3, 8, 4}, 2, 5);
  test(function,{7, 1, 5, 3, 8, 4}, 4, 3);


  test(function,{7, 1, 5, 3, 8, 4}, 10, 0);
  test(function,{1, 3, 2, 8, 4, 9}, 2, 8);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // __H__