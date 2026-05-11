struct ListNode {
  int val {};
  ListNode* next {};

  ListNode() = default;
  explicit ListNode(int val) : val{val} {}
  ListNode(int val, ListNode* next) : val{val}, next{next} {}
};

// IMPLEMENT: remove nth node from end
ListNode* removeNthFromEnd(ListNode* head, int n);

#include "test/04.h"
int main() {
  run_tests("remove nth from end", removeNthFromEnd);
  return 0;
}
