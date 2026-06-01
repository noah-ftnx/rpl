struct Node {
  int data;
  Node *next;
  Node *bottom;

  Node(int x) {
    data = x;
    next = nullptr;
    bottom = nullptr;
  }
};

// IMPLEMENT: flatten the linked list
Node *flatten(Node *root);
