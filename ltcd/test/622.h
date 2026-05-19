#ifndef RPL_LTCD_TEST_622_H_
#define RPL_LTCD_TEST_622_H_

#include "../../.inc/base.h"
#include <iomanip>
#include <string>
using namespace std;

void check_bool(string name, bool result, bool correct) {
  bool wrong = result != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(28) << name;
  cout << boolalpha << " -> " << result;
  if (wrong) cout << " (Expected: " << correct << ")";
  cout << endl;
}

void check_int(string name, int result, int correct) {
  bool wrong = result != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(28) << name;
  cout << " -> " << result;
  if (wrong) cout << " (Expected: " << correct << ")";
  cout << endl;
}

void test_lc_sample() {
  cout << "sample" << endl;
  MyCircularQueue q(3);
  check_bool("enQueue 1", q.enQueue(1), true);
  check_bool("enQueue 2", q.enQueue(2), true);
  check_bool("enQueue 3", q.enQueue(3), true);
  check_bool("enQueue 4", q.enQueue(4), false);
  check_int("Rear", q.Rear(), 3);
  check_bool("isFull", q.isFull(), true);
  check_bool("deQueue", q.deQueue(), true);
  check_bool("enQueue 4", q.enQueue(4), true);
  check_int("Rear", q.Rear(), 4);
}

void test_empty() {
  cout << "empty" << endl;
  MyCircularQueue q(2);
  check_bool("isEmpty", q.isEmpty(), true);
  check_int("Front", q.Front(), -1);
  check_int("Rear", q.Rear(), -1);
  check_bool("deQueue", q.deQueue(), false);
}

void test_wraparound() {
  cout << "wraparound" << endl;
  MyCircularQueue q(3);
  check_bool("enQueue 10", q.enQueue(10), true);
  check_bool("enQueue 20", q.enQueue(20), true);
  check_bool("enQueue 30", q.enQueue(30), true);
  check_bool("deQueue", q.deQueue(), true);
  check_bool("deQueue", q.deQueue(), true);
  check_bool("enQueue 40", q.enQueue(40), true);
  check_bool("enQueue 50", q.enQueue(50), true);
  check_int("Front", q.Front(), 30);
  check_int("Rear", q.Rear(), 50);
  check_bool("isFull", q.isFull(), true);
}

void test_capacity_one() {
  cout << "capacity one" << endl;
  MyCircularQueue q(1);
  check_bool("enQueue 7", q.enQueue(7), true);
  check_bool("isFull", q.isFull(), true);
  check_bool("enQueue 8", q.enQueue(8), false);
  check_int("Front", q.Front(), 7);
  check_int("Rear", q.Rear(), 7);
  check_bool("deQueue", q.deQueue(), true);
  check_bool("isEmpty", q.isEmpty(), true);
  check_bool("enQueue 9", q.enQueue(9), true);
  check_int("Front", q.Front(), 9);
}

void run_tests() {
  test_lc_sample();
  cout << endl;
  test_empty();
  cout << endl;
  test_wraparound();
  cout << endl;
  test_capacity_one();

  print_report();
}

#endif  // RPL_LTCD_TEST_622_H_
