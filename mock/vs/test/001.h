#ifndef INC_070__CPP_MOCK_VS_001_H_
#define INC_070__CPP_MOCK_VS_001_H_

#include <iostream>

bool _wrong=false;

void test(vector<int> vec, int correct) {
  int result = lowestCantMake(vec);
  bool wrong = result!=correct;
  _wrong|=wrong;
  cout << "result: "<< result << (wrong? " (WRONG)": "") << endl;
}

void run_tests() {

  test({}, 1);
  test({1}, 2);
  test({2}, 1);
  test({1,2}, 4);
  test({1,2,3}, 7);
  test({1,3}, 2);
  test({1,2,5}, 4);
  test({1,2,4}, 8);
  test({5, 7, 1, 1, 2, 3, 22}, 20);

}

#endif  // INC_070__CPP_MOCK_VS_001_H_
