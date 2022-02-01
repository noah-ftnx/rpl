#include <vector>
#include <queue>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int n) : data{n} {}
};

struct List {
  Node* head {};
  Node* tail {};

  bool empty() {
    return head==nullptr;
  }

  void push_back(int n) {
    auto node = new Node(n);
    push_back(node);
  }

  void push_back(Node* n) {
    n->next=nullptr;
    if (head == nullptr) {
      head=tail=n;
    } else { // push back
      tail->next=n;
      tail=n;
    }
  }
};

struct NodeCmp {
  bool operator()(Node* a, Node* b) {
    return a->data > b->data; // min heap
  }
};

List* merge_k_lists(vector<List*> lists) {
  priority_queue<Node*, vector<Node*>, NodeCmp> pq;
  List* result = new List();

  for (auto list: lists) {
    if (!list->empty()) pq.push(list->head);
  }
  while (!pq.empty()) {
    Node* min = pq.top(); pq.pop();
    auto next = min->next;
    result->push_back(min);
    if (next != nullptr) pq.push(next);
  }

  return result;
}

#include "test/006b.h"
int main() { run_tests(); return 0; }