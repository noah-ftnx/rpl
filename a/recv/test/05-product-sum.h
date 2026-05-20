#ifndef RPL_A_RECV_TEST_05_PRODUCT_SUM_H_
#define RPL_A_RECV_TEST_05_PRODUCT_SUM_H_

#include "../../../.inc/base.h"
#include <iomanip>
#include <string>
using namespace std;

void check(string name, vector<any> input, int correct) {
  int result = productSum(input);
  bool wrong = result != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(18) << name;
  cout << " -> " << setw(4) << result;
  if (wrong) cout << " Expected: " << correct;
  cout << endl;
}

void run_tests() {
  check("empty", {}, 0);
  check("flat", {1, 2, 3}, 6);
  check("simple nested", {5, 2, vector<any>{7, -1}, 3}, 22);
  check("two nested", {1, vector<any>{2, 3}, vector<any>{4}}, 19);
  check("negative nums", {1, vector<any>{-2, 3}, 4}, 7);
  check("deep single", {vector<any>{vector<any>{vector<any>{vector<any>{2}}}}}, 240);
  check("ae sample", {5, 2, vector<any>{7, -1}, 3, vector<any>{6, vector<any>{-13, 8}, 4}}, 12);

  print_report();
}

#endif  // RPL_A_RECV_TEST_05_PRODUCT_SUM_H_
