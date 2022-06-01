Node* copyRandomList1(Node* head) {
  if (head==nullptr) return head;

  Node* BH = new Node(0);
  auto prev=BH;
  auto cur=head;
  // orig, and new
  unordered_map<Node*, Node*> mp;
  //     1->2->3
  //BH-> 1->2->3
  while(cur) {
    auto cpy=new Node(cur->val);
    prev->next=cpy;
    mp.insert({cur, cpy});

    cur=cur->next;
    prev=cpy;
  }

  cur=head;
  auto cpy=BH->next;
  while(cur) {
    auto newRandom=mp[cur->random];
    cpy->random=newRandom;

    cpy=cpy->next;
    cur=cur->next;
  }

  return BH->next;
}



Node* copyRandomList(Node* head) {
  if (!head) return nullptr;
  // convention: new nodes: start w/ n
  // orig nodes: start with o

  // create new nodes (n):
  // put orig nodes random in new node next
  // and override orig node random with new node
  auto cur=head;
  while(cur) {
    auto nn = new Node(cur->val);
    nn->next=cur->random;
    cur->random=nn;

    cur=cur->next;
  }


  // put correct random value in new nodes
  // (fixing those first as they jump randomly)
  cur=head;
  while (cur) {
    auto nn = cur->random;
    auto cRand=nn->next;
    Node* nnRand=nullptr;
    if (cRand) nnRand=cRand->random;
    nn->random=nnRand;

    cur=cur->next;
  }


  cur=head;
  Node* resultHead=nullptr;
  while (cur) {
    auto nn = cur->random;
    if (!resultHead) resultHead=nn;
    auto cRand=nn->next;
    auto cNext=cur->next;
    Node* nnNext=nullptr;
    if (cNext) nnNext=cNext->random;
    nn->next=nnNext;
    cur->random=cRand;

    cur=cNext;
  }
  return resultHead;
}