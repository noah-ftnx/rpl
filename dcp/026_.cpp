
struct Node {
  Node* next{};
  int data;
  Node(int d) : data{d} {}
};

struct List {
  Node *head{}, *tail{};

  void insert(int d) {
    auto node = new Node(d);
    if (head==nullptr) {
      head=tail=node;
    } else {
      tail->next=node;
      tail=node;
    }
  }
};

// 1 -> 2 -> 3. k=0: del 3

// 1 -> 2 -> 3. k=1: del 2

// 1 -> 2 -> 3. k=2: del 1
void delete_kth(List* list, int k) {
  k++;
  Node* f = list->head;
  while(k--) { f = f->next; }

  Node* s {};
  while (f) {
    f=f->next;
    s= s==nullptr?list->head:s->next;
  }

  Node* to_del;
  if (s == nullptr) { // del head
    to_del=list->head;
    list->head=list->head->next;
  } else {
    to_del=s->next;
    if (to_del==list->tail) { // del tail
      list->tail=s;
      s->next=nullptr;
    } else {
      s->next=s->next->next;
    }
  }
  delete to_del;
}



#include "test/026.h"
int main() { run_tests(); return 0; }