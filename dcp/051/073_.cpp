
struct Node {
  int data;
  Node *next{};

  Node(int d) : data{d} {}
};

#include <utility>
using namespace std;

struct List {
  Node *head{}, *tail{};

  void insert(int val) {
    auto node = new Node(val);
    if (head==nullptr) {
      head=tail=node;
    } else {
      tail->next=node;
      tail=node;
    }
  }

  void reverse() {
    Node* prev {}, *cur=head;
    while (cur) {
      Node* next=cur->next;
      cur->next=prev;

      prev=cur;
      cur=next;
    }

    Node* tmp=head;
    head=tail;
    tail=tmp;
  }
};



#include "test/073.h"
int main() { run_tests(); return 0; }