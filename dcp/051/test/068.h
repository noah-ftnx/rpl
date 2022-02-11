#ifndef RPL_DCP_051_TEST_068_H_
#define RPL_DCP_051_TEST_068_H_


#include "base.h"
void test(vector<pair<int, int>> bishops, int M, int correct) {
  int result = bishop_attacks(bishops, M);
  bool wrong = result!=correct;
  _wrong|=wrong;
  cout << "attacks: " << result
       << (wrong? " (WRONG)": "") << endl;
}

void run_tests() {
  test({{0, 0},
          {1, 2},
          {2, 2},
          {4, 0}}, 5, 2);
  test({{0, 0},
        {1, 2},
        {2, 2},
        {3, 3},
        {4, 0}}, 5, 4);

  test({{0, 0},
        {1, 2},
        {2, 1},
        {2, 2},
        {3, 3},
        {4, 0}}, 5, 5);


}


#endif  // RPL_DCP_051_TEST_068_H_