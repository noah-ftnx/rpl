struct ListNode {
  int val {};
  ListNode* next {};

  ListNode() = default;
  explicit ListNode(int val) : val{val} {}
  ListNode(int val, ListNode* next) : val{val}, next{next} {}
};

// IMPLEMENT: reverse a linked list
ListNode* reverseList(ListNode* head);
