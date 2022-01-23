
struct Node {
  int data;
  Node* next {};

  Node(int data) : data{data} {}
};

struct List {
  Node* head{};
  Node* tail{};

  void insert(int i) {
    Node* node = new Node(i);
    if (head == nullptr) {
      head=tail=node;
    } else {
      tail->next=node;
      tail=node;
    }
  }

};


void delete_kth(List* list, int k) {

  if (list->head==nullptr) return;

  // advance the fast pointer
  int fast_steps=k+1; // excluding init to head
  Node* fast=list->head;
  while (fast_steps-- > 0) {
    fast=fast->next;
  }

  // move both pointers
  Node* slow {};
  while (fast != nullptr) {
    fast=fast->next;
    slow = slow==nullptr? list->head: slow->next;
  }

  Node* to_del;
  if (slow == nullptr) { // delete the head
    to_del=list->head;
    list->head=list->head->next;
  } else {
   to_del=slow->next;
   if (slow->next==list->tail) {
     slow->next=nullptr;
     list->tail=slow;
   } else {
     slow->next=slow->next->next;
   }
  }

  delete(to_del);
}



#include "test/026.h"
int main() { run_tests(); return 0; }