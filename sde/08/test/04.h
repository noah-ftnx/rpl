#ifndef RPL_SDE_08_TEST_04_H_
#define RPL_SDE_08_TEST_04_H_

#include "../../../.inc/base.h"
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void check(string name, int W, vector<Item> items, double correct) {
  double result = fractionalKnapsack(W, items.data(), items.size());
  bool wrong = fabs(result - correct) > 1e-6;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(18) << name;
  cout << "W=" << setw(3) << W << " ";
  cout << "items=" << setw(2) << items.size();
  cout << fixed << setprecision(2) << " -> " << result;
  if (wrong) cout << " (Expected: " << correct << ")";
  cout << endl;
}

void run_tests() {
  check("g4g sample", 50, {{60, 10}, {100, 20}, {120, 30}}, 240.0);
  check("only fraction", 3, {{10, 5}}, 6.0);
  check("take all", 100, {{10, 5}, {20, 10}}, 30.0);
  check("ratio order", 5, {{12, 4}, {10, 2}}, 19.0);
  check("zero capacity", 0, {{60, 10}, {100, 20}}, 0.0);
  cout << endl;
  print_report();
}

#endif  // RPL_SDE_08_TEST_04_H_
