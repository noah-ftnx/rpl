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

void run_tests() {
  test(input1(), true);
  test(input2(), false);
}

#endif  // RPL_DCP_TEST_032_H_
