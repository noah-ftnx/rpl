ListNode* removeNthFromEndBF(ListNode* head, int n) {
  if (head==nullptr) return nullptr;

  ListNode* cur=head;
  int sz=0;
  while (cur) {
    sz++; cur=cur->next;
  }

  cur=head;
  ListNode *prev = nullptr;
  int delIdx=sz-n;
  int i=0;
  while (cur != nullptr && delIdx-- > 0) {

    prev=cur;
    cur=cur->next;
  }

  if (prev==nullptr) {
    // removing head
    prev=head;
    head=head->next;
    delete prev;
  } else {
    prev->next=cur->next;
    delete cur;
  }

  return head;
}



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

/**
 * Overkill application of turtoise and hare
 */
ListNode* removeNthFromEndBAD(ListNode* head, int n) {
  if (head==nullptr) return nullptr;

  int SZ=0;
  ListNode *slow=head, *fast=head;
  while (fast != nullptr && fast->next!=nullptr) {
    slow=slow->next;
    fast=fast->next;
    fast=fast->next;
    SZ+=2;
  }
  // odd number of items in list
  if (fast!=nullptr) SZ++;

  if (n>SZ) return head; // OOB deletion

  int delIdx = SZ-n+1;
  int midIdx = (SZ/2)+1;

  // 5-5+1=1: del head
  // 5-4+1=1: del head->next
  // 5-3+1=2: del mid
  // 5-1+1=4: del tail
  // if delIdx is 4: move 1 place and delete that node
  // but I need prev so
  ListNode* prev=nullptr; // prev of deletion
  int move=0;
  if (delIdx > midIdx) {
    // search from slow to end
    move=delIdx-midIdx-1; // delete the ->next after these movements
    prev=slow;
  } else {
    // search from start to slow
    move=delIdx-1;
    if (move!=0) { // not deleting head
      prev=head;
      move--;
    }
  }

  while (move--) {
    prev=prev->next;
  }

  if (prev==nullptr) {
    // deleting head
    prev=head;
    head=head->next;
    delete prev;
  } else {
    auto toDel = prev->next; // can't be null because we won't stop at tail
    prev->next= prev->next==nullptr? nullptr : prev->next->next;
    delete toDel;
  }

  return head;
}



ListNode* removeNthFromEndOPT(ListNode* head, int n) {
  if (head==nullptr) return nullptr;

  ListNode *dummy= new ListNode(0);
  dummy->next=head;
  ListNode *fast=dummy, *slow=dummy;
  // put fast pointer n places in front of slow
  while (fast && n-- > 0) {
    fast=fast->next;
  }

  if (fast==nullptr || fast==dummy) return head; // invalid deletion

  // if it was null from the beginning: delete head
  while(fast->next != nullptr) {
    fast=fast->next;
    slow=slow->next;
  }


  if (slow == dummy) { // deleting head
    head=head->next;
  }

  auto toDel = slow->next;
  slow->next=slow->next->next;
  delete toDel;

  // alt: return dummy->next: handles all cases of head


  return head;
}