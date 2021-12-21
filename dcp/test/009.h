#ifndef RPL_DCP_TEST_009_H_
#define RPL_DCP_TEST_009_H_

#include <iostream>

void check(string msg, vector<int> v, int correct) {
  int r = sum_of_non_adjacent(v);
  cout << msg << ": " << r << (v!=correct? " (WRONG)": "")  << endl;
}

void run_tests() {
  vector<int> v0 {};
  vector<int> v1 {1};
  vector<int> v2 {101, 50};
  vector<int> v3 {2,4,6,2,5};
  vector<int> v4 {5,1,1,5};
  vector<int> v5 {5, 11, 1, 1, 1, 1, 300, 3};

  cout << "v0: " << sum_bu(v0) << endl;
  cout << "v1: " << sum_bu(v1) << endl;
  cout << "v2: " << sum_bu(v2) << endl;
  cout << "v3: " << sum_bu(v3) << endl;
  cout << "v4: " << sum_bu(v4) << endl;
  cout << "v5: " << sum_bu(v5) << endl;

}

#endif  // RPL_DCP_TEST_009_H_
