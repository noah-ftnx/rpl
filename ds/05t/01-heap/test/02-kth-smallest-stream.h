#ifndef RPL_DS_05T_01_HEAP_TEST_02_KTH_SMALLEST_STREAM_H_
#define RPL_DS_05T_01_HEAP_TEST_02_KTH_SMALLEST_STREAM_H_

#include "02-kth-smallest-stream-pre.h"

string show(optional<int> value) {
  if (!value) return "<none>";
  return to_string(*value);
}

string show(const vector<optional<int>>& vec) {
  string res;
  for (auto value: vec) {
    if (!res.empty()) res += " ";
    res += show(value);
  }
  return res;
}

void test(string msg, int k, vector<int> input, vector<optional<int>> correct) {
  KthSmallest kth(k);
  vector<optional<int>> result;
  for (auto val: input)
    result.push_back(kth.add(val));

  bool wrong = result != correct;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << msg << ": " << show(result);
  if (wrong) cout << " Expected: " << show(correct);
  cout << endl;
}

void run_tests() {
  test("kth-stream:1 k=3", 3, {4, 5, 8, 2, 3, 10, 1},
       {{}, {}, 8, 5, 4, 4, 3});

  test("kth-stream:2 k=1", 1, {5, 3, 8, 2},
       {5, 3, 3, 2});

  test("kth-stream:3 k=4", 4, {7, 10, 4, 3, 20, 15},
       {{}, {}, {}, 10, 10, 10});

  test("kth-stream:4 duplicates", 2, {5, 5, 1, 5},
       {{}, 5, 5, 5});

  test("kth-stream:5 negatives", 3, {-1, -5, 0, -3},
       {{}, {}, 0, -1});

  test("kth-stream:6 k=0", 0, {3, 1, 2},
       {{}, {}, {}});

  cout << endl;
}

#endif  // RPL_DS_05T_01_HEAP_TEST_02_KTH_SMALLEST_STREAM_H_
