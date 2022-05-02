#ifndef INC_070__CPP_A_DP_TUF_TEST_DP003_H_
#define INC_070__CPP_A_DP_TUF_TEST_DP003_H_

#include <iostream>
#include <iomanip>
using namespace std;

int prototype(int n, int k, vector<int> &heights);
using fptr = decltype(prototype);

bool _wrong;
void test(fptr function, int in1, int in2, vector<int> in3, int correct) {
  auto result = function(in1, in2, in3);
  bool wrong = result !=correct;
  _wrong|=wrong;
  cout << setw(3) << in1 << ": " << " K: " << setw(in2);
  string s1;
  for (int i: in3) s1+= to_string(i) + " ";
  cout << setw(25) << s1 << " Cost: " << setw(2) << result << (wrong? " (WRONG)":"") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";
  test(function, 10, 2,  {0}, -1);
  test(function, 1, 2, {10, 30, 20, 30, 10, 30}, 0);
  test(function, 4, 2, {10, 20, 30, 10}, 20);
  test(function, 6, 2, {10, 30, 20, 30, 10, 30}, 20);
  test(function, 6, 2, {30, 10, 60, 10, 60, 50}, 40);


  test(function, 4, 4, {10, 20, 30, 10}, 0);
  test(function, 4, 3, {10, 20, 30, 20}, 10);
  test(function, 6, 5, {10, 30, 20, 30, 10, 30}, 20);
  test(function, 6, 3, {30, 10, 60, 50, 10, 50, 60, 10}, 20);

  cout << endl;
}

void print_errors() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}


#endif  // INC_070__CPP_A_DP_TUF_TEST_DP003_H_