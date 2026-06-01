struct ListNode {
  int val {};
  ListNode* next {};

  ListNode() = default;
  explicit ListNode(int val) : val{val} {}
  ListNode(int val, ListNode* next) : val{val}, next{next} {}
};

// IMPLEMENT: find the middle node
ListNode* middleNode(ListNode* head);
