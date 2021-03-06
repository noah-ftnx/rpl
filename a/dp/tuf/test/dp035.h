#ifndef __H__
#define __H__

#include <string>
#include <iostream>
#include <iomanip>

int prototype(vector<int> &prices);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> prices, int correct) {
  int result = function(prices);
  bool wrong = result !=correct;
  _wrong|=wrong;
  string s;
  for (int p: prices) s += to_string(p) + " ";
  cout << setw(15) << (s.empty()?"{}":s) << " ";
  cout << "\tProfit: " << setw(3) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function,{1, 2}, 1);
  test(function,{1, 11}, 10);
  test(function,{7, 1, 5, 3, 6, 4}, 5);

  test(function, {9, 11, 8, 5, 7, 10}, 5);
  test(function, {}, 0);
  test(function, {10}, 0);
  test(function, {10, 11}, 1);
  test(function, {11, 10}, 0);
  test(function, {11, 10, 9, 8, 10}, 2);
  test(function, {9, 11, 8, 5, 4, 7, 10}, 6);


  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // __H__