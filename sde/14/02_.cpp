#include <unordered_map>
using namespace std;

struct Node {
  int key, value;
  Node *next{}, *prev{};
  Node(int k, int v): key{k}, value{v} {}
};

class List {
 public:
  Node *head{}, *tail{};

  void make_most_recent(Node* node) {
    if (node==head) return; // already most recent

    // tail migh be updated
    if (node==tail) tail=tail->prev;

    node->prev->next=node->next;
    if (node->next) node->next->prev=node->prev;

    node->next=node->prev=nullptr; // unbind the node

    node->next=head;
    head->prev=node;
    head=node;
  }

  int evictLRU() {
    // delete lru item from list & return its key
    // must evict tail
    // if (tail==nullptr) return INT_MIN;

    auto toDel = tail;
    int key = tail->key;

    if (tail==head) {
      tail=head=nullptr;
    } else {
      tail=tail->prev;
      tail->next=nullptr;
    }

    delete toDel;
    return key;
  }

  Node* push_front(int k, int v) {
    // add to front of a list (push_front)
    auto node = new Node(k, v);
    if (head==nullptr) {
      head=tail=node;
    } else {
      node->next=head;
      head->prev=node;
      head=node;
    }
    return node;
  }

};

class LRUCache {
 private:

  const int capacity;
  List list;
  unordered_map<int, Node*> mp;    // key -> Node (of the list)

  void insert(int k, int v) {
    // runs only when space is enough
    auto node = list.push_front(k, v);
    mp[k]=node;
  }

  void evict() {
    int key = list.evictLRU();
    mp.erase(key);
  }

  size_t size() { return mp.size(); }

  bool is_full() { return size() == capacity; }

 public:

  LRUCache(int c) : capacity{c} { }

  int get(int key) { // O(1)
    if (mp.count(key)==0) return -1; // not found

    auto node=mp[key];
    int value=node->value;
    list.make_most_recent(node);

    return value;
  }

  void put(int key, int value) { // O(1)
    if (mp.count(key)>0) { // exists:
      auto node = mp[key];
      node->value=value; // update value
      list.make_most_recent(node);
    } else {
      if (is_full()) evict();

      insert(key, value);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */