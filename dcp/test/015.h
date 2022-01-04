#ifndef RPL_DCP_TEST_015_H_
#define RPL_DCP_TEST_015_H_

#include <iostream>
void run_tests() {
  int r = (rand()+100)%1000;
  cout << "stream size: " << r << endl;
  vector<int> vec;
  for (int i=0; i<r; i++) {
    vec.push_back(rand());
  }

  cout << "picked from stream: " << pick_element(vec) << endl;
}

#endif  // RPL_DCP_TEST_015_H_
