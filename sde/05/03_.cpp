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


ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2) {
  ListNode *c1=list1, *c2=list2;
  ListNode *head=nullptr, *mnNode=nullptr;

  while (c1 && c2) {
    if (c1->val <= c2->val) {
      if (mnNode) mnNode->next = c1;

      mnNode=c1;
      c1=c1->next;
      mnNode->next=nullptr;
    } else {
      if (mnNode) mnNode->next = c2;

      mnNode=c2;
      c2=c2->next;
      mnNode->next=nullptr;
    }

    if (head==nullptr) head=mnNode;
  }

  // loop never entered: at least one of them is null
  // deal with: at least one list was null
  if (head==nullptr) return c2==nullptr? c1: c2;

  // one list was bigger than the other
  if (c1) mnNode->next=c1;
  if (c2) mnNode->next=c2;

  return head;
}



ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
  // either or both lists were null
  if (list1 == nullptr || list2 == nullptr)
    return list2==nullptr? list1:list2;

  ListNode *small=list1, *big=list2;
  if (list2->val < list1->val) {
    swap(small, big);
  }

  ListNode* head=small;
  while(small!=nullptr) {
    auto *next = small->next;
    // small list finished
    if (small->next == nullptr) { // finished small list
      // link to whatever items remain in the big list
      small->next=big;
      small=next;
      // next value is smaller than big
    } else if (small->next->val <= big->val) {
      small=next; // advance small
    } else { // swap small/big lists
      small->next=big;
      small=big;
      big=next;
    }
  }
  return head;
}