#ifndef RPL_DCP_TEST_033_H_
#define RPL_DCP_TEST_033_H_

#include <iostream>
#include <iomanip>

void test(vector<int> stream, vector<double> correct) {
  Processor p;
  for (int i=0; i<stream.size(); i++) {
    p.insert(stream[i]);
    double result = p.median();
    cout << setw(3) << stream[i] << " -> " << setw(3) << result
         << (result!=correct[i]? " (WRONG)": "") << endl;
  }
}

void run_tests() {
  vector<int> stream {2, 1, 5, 7, 2, 0, 5};
  vector<double> result {2, 1.5, 2, 3.5, 2, 2, 2};

  test(stream, result);
}

#endif  // RPL_DCP_TEST_033_H_
