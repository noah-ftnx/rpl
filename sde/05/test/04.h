#ifndef RPL_SDE_05_TEST_04_H_
#define RPL_SDE_05_TEST_04_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

ListNode* prototype(ListNode* head, int n);
using fptr = decltype(prototype);

bool _wrong = false;

ListNode* build_list(const vector<int>& values) {
  ListNode dummy;
  ListNode* cur = &dummy;
  for (int value : values) {
    cur->next = new ListNode(value);
    cur = cur->next;
  }
  return dummy.next;
}

string list_string(ListNode* head) {
  string result;
  for (auto cur = head; cur; cur = cur->next) {
    if (!result.empty()) result += " ";
    result += to_string(cur->val);
  }
  return result;
}

void destroy_list(ListNode* head) {
  while (head) {
    auto next = head->next;
    delete head;
    head = next;
  }
}

void check(fptr function, vector<int> values, int n, string expected) {
  auto head = build_list(values);
  auto result_head = function(head, n);
  string result = list_string(result_head);
  bool wrong = result != expected;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ")
       << "n=" << n << " -> " << result;
  if (wrong) cout << " Expected: " << expected;
  cout << endl;

  destroy_list(result_head);
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";
  check(function, {1, 2, 3, 4, 5}, 2, "1 2 3 5");
  check(function, {1}, 1, "");
  check(function, {1, 2}, 1, "1");
  check(function, {1, 2}, 2, "2");
  check(function, {1, 2, 3}, 3, "2 3");
  check(function, {1, 2, 3}, 1, "1 2");
  cout << endl << (_wrong ? "[FAIL]\n" : "[PASS]: all results.\n");
}

#endif  // RPL_SDE_05_TEST_04_H_
