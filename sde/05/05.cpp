struct ListNode {
  int val {};
  ListNode* next {};

  ListNode() = default;
  explicit ListNode(int val) : val{val} {}
  ListNode(int val, ListNode* next) : val{val}, next{next} {}
};

// IMPLEMENT: add the two numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
