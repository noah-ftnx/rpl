#ifndef RPL_DCP_TEST_023_H_
#define RPL_DCP_TEST_023_H_

#include <iostream>
#include <iomanip>

void test(bool input[N][M], pair<int, int> start, pair<int, int>end, int correct) {
  int result = min_steps(input, start, end);
  cout << "min steps: " << result << (result != correct? " (WRONG)":"") << endl;
}

void test1() {
  bool input[N][M] =
      {{0, 0, 0, 0},
       {1, 1, 0, 1},
       {0, 0, 0, 0},
       {0, 0, 0, 0}};
  pair<int, int> start {3, 0};
  pair<int, int> end {0, 0};

  test(input, start, end, 7);
}

void test2() {
  bool input[N][M] =
      {{0, 0, 0, 0},
       {1, 0, 0, 1},
       {0, 0, 0, 0},
       {0, 0, 0, 0}};
  pair<int, int> start {3, 0};
  pair<int, int> end {0, 0};

  test(input, start, end, 5);
}



void run_tests() {
  test1();
  test2();
}

#endif  // RPL_DCP_TEST_023_H_
