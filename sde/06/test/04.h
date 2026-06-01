#ifndef _H_
#define _H_

#include "../../../.inc/base.h"
#include "../../../.inc/to_string.h"

bool prototype(ListNode* head);
using fptr = decltype(prototype);

ListNode* build(vector<int> vals) {
  if (vals.empty()) return nullptr;
  ListNode* head = new ListNode(vals[0]);
  ListNode* cur = head;
  for (int i = 1; i < (int) vals.size(); i++) {
    cur->next = new ListNode(vals[i]);
    cur = cur->next;
  }
  return head;
}

vector<int> to_vec(ListNode* head) {
  vector<int> vals;
  while (head) {
    vals.push_back(head->val);
    head = head->next;
  }
  return vals;
}

void test(fptr fun, vector<int> input, bool correct) {
  auto head = build(input);
  auto before = to_vec(head);
  bool res = fun(head);
  auto after = to_vec(head);
  bool wrong = res != correct || after != before;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << to_string(before) << " -> " << boolalpha << res;
  if (wrong) cout << " Expected: " << boolalpha << correct;
  cout << endl;
}

void run_tests(fptr fun, string msg) {
  cout << msg << ":\n";
  test(fun, {}, true);
  test(fun, {1}, true);
  test(fun, {1, 2}, false);
  test(fun, {1, 2, 2, 1}, true);
  test(fun, {1, 2, 3, 2, 1}, true);
  test(fun, {1, 2, 3, 4, 5}, false);
  cout << endl;
}

#endif  // _H_
