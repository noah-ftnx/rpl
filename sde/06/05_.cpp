/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
ListNode *detectCycleOPT(ListNode *head) {

  auto fast=head, slow=head;

  while(fast!=nullptr && fast->next!=nullptr) {
    fast=fast->next->next;
    slow=slow->next;

    // if the collide: there's a cycle
    // (checking after advancement, as initially both pointed to head)
    if (fast==slow) break;
  }

  // no cycle: fast became/reaching null
  // covering also: head was null, head->next was null
  if (fast==nullptr || fast->next==nullptr) return nullptr;

  // find cycle's entrypoint
  // there will be the same distance from the beginning to the
  // entrypoint, and from the collision point to the entrypoint (from inside the cycle)
  fast=head;
  while (fast!=slow) {
    fast=fast->next;
    slow=slow->next;
  }

  return fast;
}