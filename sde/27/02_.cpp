#include <unordered_map>
#include <string>
using namespace std;

struct Node {
  unordered_map<char, Node*> child;
  int cnt=0;
  int wordsCnt=0;

  bool has(char c) { return child.count(c) > 0; }

  Node* get(char c) {
    if (!has(c)) return nullptr;
    return child[c];
  }

  void add(char c) {
    child[c]=new Node();
  }
};

class Trie{

  Node *root;

 public:

  Trie(){
    root = new Node();
  }

  void insert(string &word){
    if (word.empty()) return;

    auto node = root;
    // for the root node, it will count the number of words in trie
    // prefix "": it's a cnt of all the words..
    node->cnt++;

    for (char c: word) {
      if (!node->has(c)) {
        node->add(c);
      }
      // move to that node
      node=node->get(c);
      node->cnt++; // increase its prefix match
    }

    node->wordsCnt++;
  }

  int countWordsEqualTo(string &word){
    auto node = root;
    for (char c: word) {
      if (!node->has(c)) return 0;
      node=node->get(c);
    }
    return node->wordsCnt;
  }

  int countWordsStartingWith(string &word){
    auto node = root;
    for (char c: word) {
      if (!node->has(c)) return 0;
      node=node->get(c);
    }
    return node->cnt;
  }

  void erase(string &word){
    if (word.empty()) return;

    Node *prev {}, *node=root;
    node->cnt--;
    for (char c: word) {

      // a
      // apple
      auto next=node->get(c);
      next->cnt--;

      // next node will be deleted (on next iteration)
      if (next->cnt==0) {
        // for now: remove it's entry from its parent
        node->child.erase(c);
      }

      // the parent node has to be deleted (unless it's the parent)
      if (node->cnt==0) {
        if (node != root) { // dont delete the root
          delete node;
        }
      }

      node=next; // move to next node
    }

    if (node->cnt==0) {
      if (node!=root) {
        delete node;
      }
    } else {
      node->wordsCnt--;
    }
  }
};