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


ListNode* rotateRight1(ListNode* head, int k) {
  if (head==nullptr || k<0) return nullptr;
  int size=0;
  ListNode* cur = head;
  while (cur) { size++; cur=cur->next; }

  int rotations=k%size;

  // otherwise the code below will create a cycle
  if (rotations==0) return head;

  int targetNode = size-rotations;
  int i=0;
  cur=head;
  while (i++ <targetNode) {
    auto next=cur->next;
    if (i == targetNode) {
      // the last rotation:
      // before advancing cur to the new head
      // we have to unbind the new tail
      cur->next=nullptr;
    }
    cur=next;
  }

  ListNode *const newHead=cur;
  // find the last node and point it to old head
  while (cur->next != nullptr) cur=cur->next;
  cur->next=head;

  return newHead;
}


ListNode* rotateRight(ListNode* head, int k) {
  if (head==nullptr || k<0) return nullptr;

  int size=1;
  ListNode *cur = head;
  while (cur->next && ++size) { cur=cur->next; }

  ListNode *const lastNode=cur;
  lastNode->next=head;

  int rotations=k%size;

  // N:5, and target is the 5th node:
  // do 4 movements (as we are already on the head node)
  // or if we have to move to 1st node (head), we are already there
  int targetNode = size-rotations-1;
  cur=head;
  while (targetNode--) cur=cur->next;

  head=cur->next; // new head
  cur->next=nullptr; // new tail

  return head;
}