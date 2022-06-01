/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

ListNode *getIntersectionNodeBF(ListNode *headA, ListNode *headB) {
  ListNode *ca=headA;

  while (ca) {
    ListNode* cb=headB;
    while (cb) {
      if (ca==cb) return ca;

      cb=cb->next;
    }
    ca=ca->next;
  }
  return nullptr;
}



#include <unordered_set>
using namespace std;

ListNode *getIntersectionNodeSol1(ListNode *headA, ListNode *headB) {
  unordered_set<ListNode*> st;
  ListNode *ca=headA, *cb=headB;

  // add all node addresses in a set
  while(ca) {
    st.insert(ca);
    ca=ca->next;
  }

  // if any B addresses already in the set, return it
  while(cb) {
    if (st.count(cb)) return cb;
    cb=cb->next;
  }

  return nullptr;
}


ListNode *getIntersectionNodeBUGGY_EXP(ListNode *headA, ListNode *headB) {
  uintptr_t xptr = 0;

  ListNode *ca=headA; //, *cb=headB;
  while (ca) { // prefix xor for ca
    xptr = reinterpret_cast<uintptr_t>(ca) xor xptr;
    ca=ca->next;
  }

  ListNode *cb=headB;
  while (cb) { // prefix xor for ca
    xptr = reinterpret_cast<uintptr_t>(cb) xor xptr;
    cb=cb->next;
  }

  // cancelled out the effect of the common pointers

  // xor out items that do not match with the xptr
  ca=headA; //, *cb=headB;
  while (ca) { // prefix xor for ca
    if (xptr==0) break;

    xptr = reinterpret_cast<uintptr_t>(ca) xor xptr;
    ca=ca->next;

  }

  return ca;
}


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  if (!headA || !headB) return nullptr;

  int sza =0;
  auto ca = headA;
  while (ca) {
    sza++;
    ca=ca->next;
  }

  int szb =0;
  auto cb = headB;
  while (cb) {
    szb++;
    cb=cb->next;
  }

  int diff;
  // assume equal sizes, so both start from head
  ca=headA;
  cb=headB;
  if (sza>szb) {
    diff=sza-szb;
    ca=headA;
    while(ca && diff--) ca=ca->next;
    cb=headB;
  } else if (szb>sza) {
    diff=szb-sza;
    cb=headB;
    while(cb && diff--) cb=cb->next;

    ca=headA;
  } // else: both are equal: no advancements

  while (ca != cb) {
    ca=ca->next;
    cb=cb->next;
  }
  // either they match, or they advance both to null pointers
  // (the have the same len. plus they'll match at both being null)
  return ca; // cb would also do
}


ListNode *getIntersectionNodeOPT2(ListNode *headA, ListNode *headB) {
  if (!headA || !headB) return nullptr;

  auto ca=headA, cb=headB;
  // loop1: advance until either reaches end (the short list)
  while(ca && cb) {
    ca=ca->next;
    cb=cb->next;
  }

  // put short list to the bigger list
  if (!ca) {
    ca=headB;
  }

  if(!cb) {
    cb=headA;
  }

  // loop 2: until they the 2nd pointer reaches the end (the bigger list)
  // edge cases: 1. identical lists 2. no common element lists (covered)
  while(ca && cb) {
    ca=ca->next;
    cb=cb->next;
  }

  if (!ca) {
    ca=headB;
  }

  if(!cb) {
    cb=headA;
  }

  // loop 3: if they match: return
  while(ca && cb) {
    if (ca==cb) return ca;
    ca=ca->next;
    cb=cb->next;
  }

  return nullptr;
}

ListNode *getIntersectionNodeOPT2_short(ListNode *headA, ListNode *headB) {
  if (!headA || !headB) return nullptr;

  auto ca=headA, cb=headB;
  // loop1: advance until either reaches end (the short list)
  while(ca != cb) {
    // advance to next, but if reached null swap list
    ca= ca==nullptr? headB : ca->next;
    // advance to next, but if reached null swap list
    cb= cb==nullptr? headA : cb->next;
  }

  return ca; // either equal or null
}