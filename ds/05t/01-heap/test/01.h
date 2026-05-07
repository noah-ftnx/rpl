#ifndef _H_
#define _H_

#include "../../../../.inc/base.h"
#include "../../../../.inc/to_string.h"

void push_all(MinHeap &heap, const vector<int> &input) {
  for (int v: input) heap.push(v);
}

vector<int> pop_all(MinHeap &heap) {
  vector<int> res;
  while (!heap.empty()) {
    res.push_back(heap.top());
    heap.pop();
  }
  return res;
}

void test(string name, vector<int> input, vector<int> correct) {
  MinHeap heap;
  push_all(heap, input);

  bool wrong = heap.size() != (int) input.size();
  auto output = pop_all(heap);
  wrong |= output != correct;
  wrong |= !heap.empty();
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << setw(18) << name;
  cout << setw(42) << to_string(input, 1);
  cout << " -> ";
  cout << to_string(output, 1);
  if (wrong) cout << " (WRONG. Expected: " << to_string(correct, 1) << ")";
  cout << endl;
}

void test_pop_empty() {
  MinHeap heap;
  heap.pop();

  bool wrong = !heap.empty() || heap.size() != 0;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << setw(18) << "pop empty";
  cout << setw(42) << "[]";
  cout << " -> ";
  cout << "[]";
  if (wrong) cout << " (WRONG. Expected: [])";
  cout << endl;
}

void run_tests(string msg) {
  cout << msg << ":\n";
  test_pop_empty();
  test("mixed", {9, 25, 3, 10, 6, 4, 15, 2, 8, 40, 24}, {2, 3, 4, 6, 8, 9, 10, 15, 24, 25, 40});
  test("already heap", {2, 6, 3, 8, 9, 4, 15}, {2, 3, 4, 6, 8, 9, 15});
  test("descending", {9, 8, 7, 6, 5, 4, 3}, {3, 4, 5, 6, 7, 8, 9});
  test("one item", {3}, {3});
  test("duplicates", {5, 1, 5, 1, 3}, {1, 1, 3, 5, 5});
  cout << endl;
}

#endif  // _H_
