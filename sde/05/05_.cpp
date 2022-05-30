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


ListNode* addTwoNumbersCOMPLEX(ListNode* l1, ListNode* l2) {
  ListNode *head=nullptr, *cur=nullptr;
  int carry=0;
  while(l1!= nullptr && l2!= nullptr) {
    int sum = l1->val+l2->val + carry;
    // 11
    int digit = sum%10;
    carry = (sum>=10);

    auto node = new ListNode(digit); // create new node

    // first node: save head and cur
    if (!head) { head=cur=node; }
    else { // not the first node
      cur->next=node; // prev node points to this one
    }

    cur=node;
    l1=l1->next;
    l2=l2->next;
  }

  // l1 still has digits
  while (l1!=nullptr) {
    int sum = l1->val + carry;
    int digit = sum%10;
    carry = (sum>=10);
    auto node = new ListNode(digit);
    if (!head) { head=cur=node; } // first node
    else cur->next=node; // prev node points to this one

    cur=node;
    l1=l1->next;
  }

  while (l2!=nullptr) {
    int sum = l2->val + carry;
    int digit = sum%10;
    carry = (sum>=10);
    auto node = new ListNode(digit);
    if (!head) head=cur=node;
    else cur->next=node;

    cur=node;
    l2=l2->next;
  }

  // very last carry
  if (carry==1) {
    cur->next = new ListNode(1);
  }
  return head;
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  int carry=0;
  auto befHead = new ListNode(-1);
  auto node = befHead;
  while (carry != 0 || l1 || l2) { // we have things to add to the answer
    int sum=0;

    if (l1) {  // add from l1 (if not consumed)
      sum+=l1->val;
      l1=l1->next;
    }

    if (l2) {  // add from l2 (if not consumed)
      sum+=l2->val;
      l2=l2->next;
    }

    // add carry
    sum+=carry;

    carry=sum/10; // or if bigger than 10

    auto nextNode = new ListNode(sum%10);
    node->next=nextNode;
    node=nextNode;
  }
  return befHead->next;
}