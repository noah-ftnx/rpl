struct ListNode {
  int val {};
  ListNode* next {};

  ListNode() = default;
  explicit ListNode(int val) : val{val} {}
  ListNode(int val, ListNode* next) : val{val}, next{next} {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode dummy(0, head);
  auto fast = &dummy;
  auto slow = &dummy;

  while (n-- > 0) fast = fast->next;

  while (fast->next) {
    fast = fast->next;
    slow = slow->next;
  }

  auto to_delete = slow->next;
  slow->next = slow->next->next;
  delete to_delete;

  return dummy.next;
}

#include "test/04.h"
int main() {
  run_tests("remove nth from end", removeNthFromEnd);
  return 0;
}
