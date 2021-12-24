#include <deque>
#include <vector>
using namespace std;

template <class T>
struct Node {
  T data {};
  Node<T>* left;
  Node<T>* right;
  Node<T>* parent;

  Node(T data) : data{data} {}
};

template <class T>
struct Tree {

  Node<T>* root {};

  Tree(T value) { root = new Node<T>(value); }


  void _query_successors(deque<int>& query, deque<int>& answer,
                           vector<Node<T>*> inorder, Node<T>* node) {
    if (node == nullptr) return;

    _query_successors(query, answer, inorder, node->left);
    if (query.empty()) return; // found all answers

    // visit
    //// pre-visit
    if (!inorder.empty() && inorder.back()->data == query.front()) { // one of the answers
      answer.push_back(node->data);
      query.pop_front();
      if (query.empty()) return; // found all answers
    }
    inorder.push_back(node); // actual visit

    _query_successors(query, answer, inorder, node->right);
  }

  void add(const vector<T>& data, const string& path); // given

  void query_successors(deque<int>& query, deque<int>& answer) {
    vector<Node<T>*> inorder;
    _query_successors(query, answer, inorder, root);
  }

};



#include "test/12.h"
int main() { run_tests(); return 0; }