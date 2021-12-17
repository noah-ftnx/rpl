
#include <cstdint>
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* both {};
  Node(int d) : data{d} {}

  static Node* XOR(Node* a, Node* b) {
    return reinterpret_cast<Node*>(
        reinterpret_cast<uintptr_t>(a) xor reinterpret_cast<uintptr_t>(b));
  }
};

struct XORList {
  Node* head {};
  Node* tail {};

  void add(int element) {
    auto node = new Node(element);
    if (!head) {
      head=tail=node; // no prev/next
    } else if (head==tail) {
      tail=node;
      head->both=tail; // head: pref is null, next is tail
      tail->both=head; // tail: next is null, prev is head
    } else {
      node->both=tail; // will become new tail: no next, prev is old tail
      tail->both=Node::XOR(tail->both, node); // prev: prev node (initially head), next: new tail
      tail=node;
    }
  }

  Node* get(int idx) {
    if (idx < 0) return nullptr;
    auto node = head;
    Node* prev = nullptr;
    for (int i=0; node && i<idx; i++) {
      Node* next = Node::XOR(node->both, prev);
      prev = node;
      node = next;
    }

    return node;
  }
};



//////////////////////////////////////////////////////////////////////////////////////////////////////



string get_str(Node* node) {
  if (node == nullptr) return "<nullptr>";
  return to_string(node->data);
}


void check_node(XORList* xl, int i, string res) {
  Node* node = xl->get(i);
  string str = get_str(node);
  cout << "get:"<<i<<": " << str << (str!=res?" (WRONG)": "") << endl;
}

void run_tests() {
  XORList xl;
  xl.add(10);
  xl.add(15);
  xl.add(25);
  xl.add(30);
  xl.add(50);
  xl.add(99);
  xl.add(128);

  check_node(&xl, 0, "10");
  check_node(&xl, 1, "15");
  check_node(&xl, 2, "25");
  check_node(&xl, 3, "30");
  check_node(&xl, 4, "50");
  check_node(&xl, 5, "99");
  check_node(&xl, 6, "128");

  check_node(&xl, 7, "<nullptr>");
  check_node(&xl, -10, "<nullptr>");
}

int main() { run_tests(); return 0; }
