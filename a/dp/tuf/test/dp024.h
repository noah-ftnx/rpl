#ifndef __H__
#define __H__

#include <iostream>
#include <iomanip>


int prototype(vector<int> &price, int n);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> price, int rodLen, int correct) {
  int result = function(price, rodLen);
  bool wrong = result !=correct;
  _wrong|=wrong;
  string s;
  for (int a: price) s+=to_string(a) + " ";
  if (!s.empty()) s.pop_back(); else s="{}";
  cout << setw(15) << s;

  cout << ":\t Rod len: " << setw(2) << rodLen << " Profit: ";
  cout << setw(2) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  // test(function, nullptr,  0, 1, 0);
  test(function, {4, 5}, 3, 12);
  test(function, {3, 0, 0, 0, 0, 0, 0, 20}, 10, 30);
  test(function, {2, 5, 7, 8, 10}, 10, 25);
  // test(function, {15, 8}, {7, 4}, 40);
  // test(function, {5,11,13}, {2,4,6}, 27);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // __H__