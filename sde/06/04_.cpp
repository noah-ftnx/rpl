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


ListNode* reverseList(ListNode* head) {
  ListNode *prev=nullptr, *cur=head;
  while (cur) {
    auto next=cur->next;
    cur->next=prev;
    prev=cur;
    cur=next;
  }
  return prev;
}

bool isPalindrome(ListNode* head) {
  // empty list or list with 1 element
  if (head==nullptr || head->next==nullptr) return true;

  auto fast=head, slow=head;
  ListNode* prevSlow=nullptr;
  while (fast && fast->next) {
    fast=fast->next->next;
    prevSlow=slow;
    slow=slow->next;
  }

  // reverse the 2nd half of the list
  ListNode* prevSlowNext=prevSlow->next;
  prevSlow->next=nullptr; // unbind list

  ListNode *revList = reverseList(slow);  // reverse 2nd list

  // use cur (avoids odd/even size issues: rev can have 1 extra el)
  auto cur=head, rev=revList;
  while (cur!=nullptr) {
    if (cur->val != rev->val) return false;
    cur=cur->next;
    rev=rev->next;
  }

  // fix original list:
  //  1, 2, 3, 2, 1 ->
  //  1, 2,
  //  1, 2, 3, revList
  ListNode* revRevList = reverseList(revList);
  // 2, 1
  prevSlow->next = revRevList;

  return true;
}