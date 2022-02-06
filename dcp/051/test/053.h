#ifndef RPL_DCP_051_TEST_053_H_
#define RPL_DCP_051_TEST_053_H_

#include <iostream>
#include <iomanip>
#include "../../../.check/check.h"

bool _wrong {};

void test1() {
  Queue q;

  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);

  _wrong|=check_intPrettyMin("deque", q.dequeue(), 1);
  _wrong|=check_intPrettyMin("deque", q.dequeue(), 2);

  q.enqueue(4);
  _wrong|=check_intPrettyMin("deque", q.dequeue(), 3);
  _wrong|=check_intPrettyMin("deque", q.dequeue(), 4);

  try {
    _wrong|=check_intPrettyMin("deque", q.dequeue(), 4);
  } catch (string s) {
    cout << "Exception: " << s << endl;
  }
}


void print_errors() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect.\n";
}

void run_tests() {
  test1();
  print_errors();
}


#endif  // RPL_DCP_051_TEST_053_H_