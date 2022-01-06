#ifndef RPL_DCP_TEST_020_H_
#define RPL_DCP_TEST_020_H_

#include <iostream>
using namespace std;

void test(List* l1, List* l2, int correct) {
  int result = intersecting_node(l1, l2);
  cout << "intersecting node: " << result << (result!=correct? " (WRONG)": "") << endl;
}

void test1() {
  List l1 {};
  l1.insert(3);
  l1.insert(7);
  l1.insert(8);
  l1.insert(10);

  List l2{};
  l2.insert(99);
  l2.insert(1);
  l2.insert(8);
  l2.insert(10);

  test(&l1, &l2, 8);
}

void test2() {
  test(nullptr, nullptr, INT_MIN);
}

void test3() {
  List l1{}, l2{};
  test(&l1, &l2, INT_MIN);
}

void test4() {
  List l1{}, l2{};
  l1.insert(10);
  l1.insert(15);

  l2.insert(10);
  l2.insert(15);
  test(&l1, &l2, 10);
}

void test5() {
  List l1{}, l2{};
  l1.insert(1);
  l1.insert(2);

  l2.insert(3);
  l2.insert(4);
  test(&l1, &l2, INT_MIN);
}

void test6() {
  List l1{}, l2{};
  l1.insert(1);
  l1.insert(5);

  l2.insert(3);
  l2.insert(5);
  test(&l1, &l2, 5);
}

void run_tests() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
}

#endif  // RPL_DCP_TEST_020_H_
