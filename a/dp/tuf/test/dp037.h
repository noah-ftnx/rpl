#ifndef __H__
#define __H__

#include <string>
#include <iostream>
#include <iomanip>

long prototype(vector<int> &prices);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> prices, int correct) {
  int result = function(prices);
  bool wrong = result !=correct;
  _wrong|=wrong;
  string s;
  for (int p: prices) s += to_string(p) + " ";
  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << setw(20) << (s.empty()?"{}":s) << " ";
  cout << "\tProfit: "  << setw(3) << result << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, {}, 0);
  test(function, {10}, 0);


  test(function,{7, 1, 5, 3, 6, 4}, 7);
  test(function,{7, 1, 5, 4, 5, 3, 6, 4}, 7);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "[FAIL]\n";
  else cout << "[PASS]: all results.\n";
}

#endif  // __H__