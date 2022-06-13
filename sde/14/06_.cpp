struct Node {
  long value; // modified num might overflow
  Node *next{};
  Node(long v) : value{v} {}
};


class MinStackBetter {
  Node *head{};
  deque<Node*> dq;

 public:
  MinStack() {}

  void push(int val) {
    auto node = new Node(val);
    if (head==nullptr) {
      head=node;
      dq.push_front(node);
    } else {
      node->next=head;
      head=node;

      if (val < dq.front()->value) {
        dq.push_front(node);
      }

    }
  }

  void pop() {
    if (head) {
      auto toDel = head;
      if (dq.front() == toDel) dq.pop_front();
      head=head->next;
      delete toDel;
    }
  }

  int top() {
    if (head==nullptr) return INT_MIN;
    return head->value;
  }

  int getMin() {
    if (dq.empty()) return INT_MIN;
    return dq.front()->value;
  }
};




class MinStackOPT {
  Node *head {};
  long mn=INT_MAX;
 public:
  MinStack() {

  }

  void push(int v) {
    long long value=v;

    // update min
    // first node: TRICKY: compare w/ head (not w/ INT_MAX),
    // as the latter can be a valid number
    if (head==nullptr) mn=value;
    else if (value < mn) {
      // we need to push in a stack another num that:
      // 1. would allow us to understand that is modified
      // 2. would encode in some sort prev `mn`
      long modifiedVal=-mn + 2L*value;
      mn=value;
      value=modifiedVal;
    }

    auto node = new Node(value);
    if (head==nullptr) {
      head=node;
    } else {
      node->next=head;
      head=node;
    }
  }

  void pop() {
    if (head==nullptr) return;

    if (head->value < mn) {
      // 2*mn-prevMin=head->value;
      long prevMin = -head->value+ 2L*mn;
      mn=prevMin;
    }

    auto toDel=head;
    head=head->next;
    delete toDel;
  }

  int top() {
    if (head->value < mn) return mn;
    else return head->value;
  }

  int getMin() {
    return mn; // always has the min
  }
};