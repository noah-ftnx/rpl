#ifndef RPL_DCP_TEST_016_H_
#define RPL_DCP_TEST_016_H_

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

void test(string msg, Log& log, int i, int correct) {
  int res = log.get_last(i);
  cout << setw(10) << msg << " " << i << ": " << setw(10) << res << (res!=correct? " (WRONG)":"") << endl;
}


void run_tests() {
  Log log = Log(3);
  test("empty", log, 1, INT_MIN);
  log.record(101);
  test("get", log, 0, INT_MIN); // no zero indexing
  test("get", log, 1, 101);

  log.record(102);
  test("get", log, 1, 102);
  test("get", log, 2, 101);
  log.record(103);
  test("get", log, 1, 103);
  test("get", log, 2, 102);
  test("get", log, 3, 101);

  log.record(110); // overriding
  test("get", log, 1, 110);
  test("get", log, 2, 103);
  test("get", log, 3, 102);
  // test("get", log, 4, INT_MIN); cant be > N
  test("get", log, -1, INT_MIN);
}

#endif  // RPL_DCP_TEST_016_H_
