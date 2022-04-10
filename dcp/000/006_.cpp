#include <cstdint>
using namespace std;

struct Node {
  int value;
  Node* link = nullptr;
  Node(int v) : value{v} {}
};

struct XORList {
  Node *head=nullptr, *tail=nullptr;

  static Node* XOR(Node* a, Node* b) {
    return reinterpret_cast<Node*>(
        reinterpret_cast<uintptr_t>(a)
        xor reinterpret_cast<uintptr_t>(b));
  }

  void add(int element) {
    Node *nn = new Node(element);

    if (head==nullptr) {
      head=tail=nn;
    } else {
      // do a few examples:
      // head/tail -> nn
      // head -> tail -> nn
      // head -> aa -> tail -> nn

      // aa:link: XOR(head, bb)
      // bb: old tail
      // bb is: just aa .. (aa, xor null)
      tail->link = XOR(tail->link, nn);
      nn->link=tail;
      tail=nn;
    }
  }

  Node* get(int idx) {
    Node *n = head, *prev=nullptr;
    while (n && idx--) {
      Node* next = XOR(prev, n->link);
      prev = n;
      n = next;
    }

    return n;
  }
};

#include "test/006.h"
int main() { run_tests(); return 0; }
