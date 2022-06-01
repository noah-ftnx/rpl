bool hasCycle(ListNode *head) {
  unordered_set<ListNode*> st;

  auto cur=head;
  while (cur) {
    if (st.count(cur)> 0) return true;
    st.insert(cur);
    cur=cur->next;
  }

  return false;
}


bool hasCycleOPT(ListNode *head) {
  auto fast=head, slow=head;
  while (fast && fast->next) {
    fast=fast->next;
    fast=fast->next;
    slow=slow->next;

    if (fast==slow) return true;
  }

  return false;
}