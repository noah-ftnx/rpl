#ifndef RPL_DCP_051_TEST_060_H_
#define RPL_DCP_051_TEST_060_H_

#include <iostream>
#include <iomanip>

bool prototype(vector<int> input);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> input, bool correct) {
  bool result = function(input);
  bool wrong = result !=correct;
  _wrong|=wrong;
  string s;
  for (auto i: input) s+=to_string(i) + " ";
  if (!s.empty()) s.pop_back();
  cout << setw(10) << s << ": " << boolalpha << result <<
      (wrong? " (WRONG)":"") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";
  test(function, {}, true);
  test(function, {3, 4, 3}, false);
  test(function, {3, 4, 7}, true);
  test(function, {3, 5, 4, 11},  false);
  test(function, {3, 5, 4, 12},  true);
  test(function, {15, 5, 20, 10, 35, 15, 10},  true);
  test(function, {15, 5, 20, 10, 35},  false);
  cout << endl;
}

void print_errors() {
  cout << endl <<  (_wrong?"WRONG RESULTS.": "Correct results.") << endl;
}

#endif  // RPL_DCP_051_TEST_060_H_
