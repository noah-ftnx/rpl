#include <climits>
#include <unordered_map>
using namespace std;

struct Node {
  int key, data;
  Node *next{}, *prev{};
  Node(int key, int data): key{key}, data{data} {}
};

struct List {
  Node *head{}, *tail{};

  Node* insert(int key, int data) {  // insert after head
    auto n = new Node(key, data);
    if (head==nullptr) {
      head=tail=n;
    } else {
      n->next=head;
      head->prev=n;
      head=n;
    }
    return n;
  }

  void remove(Node* ptr) {
    if (ptr==nullptr) return;

    if (ptr==head) { // first node
      if (ptr==tail) { // also, last node
        head=tail=nullptr;
      } else {
        head=head->next;
        head->prev=nullptr;
      }
    } else { // a b c
      ptr->prev->next=ptr->next;
      if (ptr == tail) {
        tail=tail->prev;
      } else {
        ptr->next->prev=ptr->prev;
      }
    }

    delete ptr;
  }

  int removeLRU() { // returns key
    if (!tail) return INT_MIN;

    int lru_key=tail->key;
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

  void remove_key(int k) {
    if (mp.contains(k)) {
      auto old_node = mp[k];
      // remove from anywhere
      mp.erase(k);
      list.remove(old_node);
    }
  }

  void evictLRU() {
    auto lru_key = list.removeLRU();
    mp.erase(lru_key);
  }

 public:
  LRU(int n): N{n} {}

  int size() { return (int) mp.size(); }

  void set(int k, int v) {
    if (mp.contains(k)) {
      // will remove and reinsert:
      // for value updates and make it MRU item
      remove_key(k);
    } else if (mp.size() == N) {
      evictLRU();
    }

    insert_item(k, v);
  }

  int get(int k) {
    int res = INT_MIN;
    if (mp.contains(k)) {
      res = mp[k]->data;

      // make item as MRU
      remove_key(k);
      insert_item(k, res);
    }

    return res;
  }
};



#include "test/052.h"
int main() { run_tests(); return 0; }