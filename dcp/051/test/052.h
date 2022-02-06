#ifndef RPL_DCP_051_TEST_052_H_
#define RPL_DCP_051_TEST_052_H_

#include <iostream>
#include <iomanip>

#include "../../../.check/check.h"

bool _wrong {};

void test1() {
  LRU lru(3);

  lru.set(3, 10);
  lru.set(2, 11);
  lru.set(2, 12);
  _wrong|=check_intPrettyMin("lru size", lru.size(), 2);

  lru.set(5, 7);
  _wrong|=check_intPrettyMin("lru size", lru.size(), 3);
  _wrong|=check_intPrettyMin("lru: get 2", lru.get(2), 12); // 2: MRU

  lru.set(15, 10); // evicts 3
  lru.set(16, 10); // evicts 5

  _wrong|=check_intPrettyMin("lru: get 2", lru.get(2), 12); // 2: MRU
  _wrong|=check_intPrettyMin("lru size", lru.get(3), INT_MIN);
  _wrong|=check_intPrettyMin("lru size", lru.get(5), INT_MIN);

  lru.set(20, 10); // evicts 15

  _wrong|=check_intPrettyMin("lru: get 15", lru.get(15), INT_MIN); // 2: MRU
  _wrong|=check_intPrettyMin("lru: get 2", lru.get(2), 12); // 2: MRU
  _wrong|=check_intPrettyMin("lru: get 20", lru.get(20), 10); // 2: MRU
  _wrong|=check_intPrettyMin("lru: get 16", lru.get(16), 10); // 2: MRU
}

void print_errors() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect.\n";
}

void run_tests() {
  test1();
  print_errors();
}



#endif  // RPL_DCP_051_TEST_052_H_