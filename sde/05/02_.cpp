/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* middleNodeBF(ListNode* head) {
  int cnt {};
  auto cur=head;
  while(cur) {
    cnt++;
    cur=cur->next;
  }

  // odd elements:
  // 1 2 3 4 5: (5/2)+1
  // 1 2 3 4
  cnt/=2;
  cur=head;

  while(cnt-- > 0) {
    cur=cur->next;
  }
  return cur;
}


ListNode* middleNode(ListNode* head) {
  auto slow=head, fast=head;

  while (fast !=nullptr && fast->next != nullptr) {
    slow=slow->next;
    fast=fast->next; // won't be null (loop condition)
    fast=fast->next;
  }
  return slow;
}