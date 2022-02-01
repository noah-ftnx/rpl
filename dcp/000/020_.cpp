#include <utility>
#include <climits>
using namespace std;

struct Node {
  int data;
  Node* next {};
  Node(int data) : data{data} {}
};

struct List {
  Node* head {};
  Node* tail {};

  void insert(int n) {
    Node* node = new Node(n);
    if (head==nullptr) {
      head=tail=node;
    } else {
      tail->next=node;
      tail=node;
    }
  }

  void reverse_nodes() {
    Node* prev {};
    Node* node = head;
    while (node != nullptr) {
      Node* t = node->next;
      node->next=prev;
      prev=node;
      node=t;
    }
    swap(head, tail);
  }
};


int intersecting_node(List* l1, List* l2) {
  if (l1 == nullptr || l2 == nullptr) return INT_MIN;

  l1->reverse_nodes();
  l2->reverse_nodes();

  Node* n1 = l1->head;
  Node* n2 = l2->head;

  if (n1 == nullptr || n2 == nullptr || n1->data != n2->data) return INT_MIN;

  while (n1->next && n2->next && n1->next->data == n2->next->data) {
   n1=n1->next;
   n2=n2->next;
  }
  int result = n1->data;

  // restore back
  l1->reverse_nodes();
  l2->reverse_nodes();

  return result;
}



#include "test/020.h"
int main() { run_tests(); return 0; }