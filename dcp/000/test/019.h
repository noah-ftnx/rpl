#ifndef RPL_DCP_TEST_019_H_
#define RPL_DCP_TEST_019_H_

#include <iostream>
#include <iomanip>

void test(vector<vector<int>> costs, int correct) {
  int result = paint_houses(costs);
  cout << "cost: " << setw(4) << result << (result!=correct? " (WRONG)":"") << endl;
}

void test1() {
  vector<vector<int>> costs = {
      {1,2,3,4},
      {1,2,1,0},
      {6,1,1,5},
      {2,3,5,5}};

  test(costs, 4);
}

void test2() {
  vector<vector<int>> costs = {
      {2, 7, 5},
      {1, 5, 3},
      {1, 6, 3}};

  test(costs, 6);
}

void test3() {
  vector<vector<int>> costs = {
      {2, 5},
      {1, 5},
      {1, 5}};

  test(costs, 8);
}

void test4() {
  vector<vector<int>> costs = {};
  test(costs, -1);
}

void test5() {
  vector<vector<int>> costs = {{}};
  test(costs, -1);
}

void test6() {
  vector<vector<int>> costs = {{5}};

  test(costs, 5);
}


void test7() {
  vector<vector<int>> costs = {
      {2},
      {1},
      {1}};

  test(costs, -1);
}

void run_tests() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
}

#endif  // RPL_DCP_TEST_019_H_
