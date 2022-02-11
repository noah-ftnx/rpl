#include <string> // for implemented methods

#include <cassert>
#include <unordered_map>
#include <climits>
using namespace std;

struct Node {
  Node *next{}, *prev{};

  int freq; // to figure out to which freq map it is
  int key;  // on eviction, to fremove it from the key/node map
  int data;

  Node(int key, int d, int freq) : key{key}, data{d}, freq{freq} {}
};

struct List {
  Node *head {}, *tail{};

  Node* insert(int key, int data, int freq) {
    Node* node = new Node(key, data, freq);
    if (head==nullptr) {
      head=tail=node;
    } else {
      // add it at the front (LRU property)
      node->next=head;
      head->prev=node;
      head=node;
    }
    return node;
  }

  bool empty() { return head==nullptr; }

  void erase(Node* node) {
    if (node == head) { // first node
      if (node==tail) { // and also the last one
        head=tail=nullptr;
      } else {
        head=head->next;
        head->prev=nullptr;
      }
    } else {
      node->prev->next=node->next;
      if (node==tail) { // last node
        tail=node->prev;
      } else {
        node->next->prev=node->prev;
      }
    }
    delete node;
  }

  int evict_lru() {
    assert(tail);
    int key = tail->key;
    erase(tail);
    return key;
  }
};

class LFU {
 private:
  const int N;
  int min_freq {0}, max_freq{0};

  // key -> node
  unordered_map<int, Node*> mp;
  // frequency -> list
  unordered_map<int, List*> freq_lists;

  int _size {};  // global sum

  void insert(int key, int value, int freq) {
    List* list;
    if (!freq_lists.contains(freq)) { // new frequency added
      list = new List();
      freq_lists.insert({freq, list});
      update_minmax_freq(freq);
    } else {
      list = freq_lists[freq];
    }

    Node* node = list->insert(key, value, freq);
    mp.insert({key, node});
    _size++;
  }

  void update_minmax_freq(int freq) {
    if (min_freq == 0 || freq < min_freq) min_freq = freq;
    if (max_freq == 0 || freq > max_freq) max_freq = freq;
  }

  void update_min_freq() {
    for (int i = min_freq; i<=max_freq; i++) {
      if (freq_lists.contains(i)) {
        min_freq=i;
        break;
      }
    }
  }

  void update_post_removal(List* lst, int freq) {
    _size--;
    if (lst->empty()) {
      freq_lists.erase(freq);
      delete lst;

      if(freq==min_freq) update_min_freq();
    }
  }

  void remove(Node* node) {  // from relevant freq list
    int freq = node->freq;
    auto lst = freq_lists[freq];

    mp.erase(node->key);
    lst->erase(node);

    update_post_removal(lst, freq);
  }

  void evict_lfu() { // CHECK min_freq?
    assert(freq_lists.contains(min_freq));
    List* lst = freq_lists[min_freq];
    int key = lst->evict_lru();
    mp.erase(key);
    update_post_removal(lst, min_freq);
  }

 public:
  LFU(int n): N{n} { }

  int size() const { return _size; }

  string to_string(); // GIVEN

  void set(int key, int value) {
    int freq {1};
    if (mp.contains(key)) { // existing entry
      // increase frequency: remove and re-add in a higher frequency LRU list
      auto node = mp[key];
      freq=node->freq+1;
      remove(node);
    } else if(_size==N) { // full, so evict
      evict_lfu();
    }
    insert(key, value, freq);
  }

  int get(int key) {
    if (!mp.contains(key)) return INT_MIN;

    // increase frequency + put in MRU position
    Node* node = mp[key];
    int freq=node->freq+1;
    int data = node->data;

    remove(node); // from prev freq list
    insert(key, data, freq); // to new freq list, in front (MRU position)

    return data;
  }
};



#include "test/067.h"
int main() { run_tests(); return 0; }