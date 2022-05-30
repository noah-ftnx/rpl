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


  while(cur) {
    ListNode* next = cur->next;
    cur->next=prev;
    prev=cur;
    cur=next;
  }

  // new head:
  // - if prev was null: we had a single item, so return head (effectively)
  // - otherwise return prev, which points to the last node (as cur will become null)
  return prev==nullptr? cur : prev;
}