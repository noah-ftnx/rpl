#ifndef RPL_DCP_TEST_032_H_
#define RPL_DCP_TEST_032_H_

#include <iostream>

void test(vector<vector<double>> rates, bool correct) {
  bool result = arbitrage(rates);
  cout << "arbitrage: " << boolalpha << result
       << (result!=correct? " (WRONG)": "") << endl;
}

vector<vector<double>> input1() {
  vector<vector<double>> rates(2, vector<double>(2));
  // there is arbitrage
  rates[0] = {1, 2};
  rates[1] = {2, 1};
  return rates;
}

vector<vector<double>> input2() {
  vector<vector<double>> rates(2, vector<double>(2));
  // there is no way to arbitrage
  rates[0] = {1, 1};
  rates[1] = {1, 1};
  return rates;
}

vector<vector<double>> input3() {
  return {
      {1, 0.23, 0.25, 16.43, 18.21, 4.94},
      {4.34, 1, 1.11, 71.40, 79.09, 21.44},
      {3.93, 0.90, 1, 64.52, 71.48, 19.37},
      {0.061, 0.014, 0.015, 1, 1.11, 0.30},
      {0.055, 0.013, 0.014, 0.90, 1, 0.27},
      {0.20, 0.047, 0.052, 3.33, 3.69, 1},
  };
}

void run_tests() {
  test(input1(), true);
  test(input2(), false);
  test(input3(), true);
}

#endif  // RPL_DCP_TEST_032_H_
