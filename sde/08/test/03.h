#ifndef RPL_SDE_08_TEST_03_H_
#define RPL_SDE_08_TEST_03_H_

#include "../../../.inc/base.h"
#include "../../../.inc/to_string.h"
#include <iomanip>
#include <vector>
using namespace std;

void check(string name, vector<Job> jobs, vector<int> correct) {
  auto input = jobs;
  auto result = JobScheduling(jobs.data(), jobs.size());
  bool wrong = result != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(22) << name;
  cout << "jobs=" << setw(2) << input.size();
  cout << " -> " << to_string(result, 1);
  if (wrong) cout << " (Expected: " << to_string(correct, 1) << ")";
  cout << endl;
}

void run_tests() {
  check("empty", {}, {0, 0});
  check("one job", {{1, 1, 50}}, {1, 50});
  check("g4g sample 1", {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}}, {2, 60});
  check("g4g sample 2", {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}}, {3, 142});
  check("same deadline", {{1, 1, 10}, {2, 1, 50}, {3, 1, 20}}, {1, 50});
  check("late slot", {{1, 3, 40}, {2, 1, 30}, {3, 2, 20}}, {3, 90});
  check("skip low profit", {{1, 2, 20}, {2, 2, 100}, {3, 1, 50}}, {2, 150});
  cout << endl;
  print_report();
}

#endif  // RPL_SDE_08_TEST_03_H_
