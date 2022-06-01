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


ListNode* reverseSublist(ListNode *groupPrev, int k) {
  ListNode *groupFirst=groupPrev->next;

  auto prev = groupFirst;
  auto cur = prev->next;
  ListNode* next {};
  while (--k) {
    next=cur->next;
    cur->next=prev;

    // advance pointers
    prev=cur;
    cur=next;
  }

  // fix first and last pointer of the reversed group

  // cur or next: is the same
  // first element (now last) points to the right(next) subGroup
  groupFirst->next=cur;
  // last element (now first) is pointed by the groups prev element
  groupPrev->next=prev;

  return groupFirst; // last element of reversed group
}

ListNode* reverseKGroup(ListNode* head, int k) {
  if (head==nullptr || k<=0) return nullptr;

  // find size of the list
  int cnt=0;
  auto cur = head;
  while(cur) {
    cnt++;
    cur=cur->next;
  }

  ListNode* befHead= new ListNode(0);
  befHead->next = head;

  auto *prev = befHead;
  while (cnt>=k) { // check head also?
    prev=reverseSublist(prev, k);
    cnt-=k;
  }
  return befHead->next;
}
