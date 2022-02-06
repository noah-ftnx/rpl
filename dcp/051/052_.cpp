#include <unordered_map>
#include <climits>
using namespace std;

struct Node {
  int key, value;
  Node *prev{}, *next{};
  Node(int k, int v) : key{k}, value{v} {}
};

struct List {
  Node *head{}, *tail{};

  Node* insert(int k, int v) {
    Node* nn = new Node(k, v);
    if (head==nullptr) {
      head=tail=nn;
    } else { // insert at MRU position (front)
      nn->next=head;
      head->prev=nn;
      head=nn;
    }
    return nn;
  }

  void remove(Node* ptr) {
    if (ptr == nullptr) return;

    if (ptr == head) {
      if (ptr == tail) head=tail=nullptr;
      else {
        head=head->next;
        head->prev=nullptr;
      }
    } else { // a b c
      ptr->prev->next=ptr->next;
      if (ptr==tail) { // a b
        tail=ptr->prev;
      } else {
        ptr->next->prev=ptr->prev;
      }
    }
    delete ptr;
  }

  int removeLRU() {
    if (tail==nullptr) return INT_MIN;

    int lru_key = tail->key;
    remove(tail);
    return lru_key;
  }
};

class LRU {
 private:
  const int N;
  unordered_map<int, Node*> mp;
  List list;

  void insert_item(int k, int v) {
    auto nn=list.insert(k, v);
    mp.insert({k, nn});
  }

  void remove_item(int k) {
    if (mp.contains(k)) {
      auto node_to_del = mp[k];
      list.remove(node_to_del);
      mp.erase(k);
    }
  }

  void evictLRU() {
    auto del_key = list.removeLRU();
    mp.erase(del_key);
  }

 public:
  LRU(int n) : N{n} {}

  int size() { return mp.size(); }

  void set(int k, int v) {
    if (mp.contains(k)) {
      // remove it for 2 reasons
      // 1. update the value if it has changed
      // 2. make it recent
      remove_item(k);
    } else if (static_cast<int>(mp.size())==N) {
      evictLRU();
    }

    insert_item(k, v);
  }

  int get(int k) {
    if (!mp.contains(k)) return INT_MIN;

    int res = mp[k]->value;
    // make it MRU
    remove_item(k);
    insert_item(k, res);
    return res;
  }
};



#include "test/052.h"
int main() { run_tests(); return 0; }