#include "test/bst-tmpl-succpred-recv.h"

// TEMPLATE:
// Node<T>* Tree<T>::successor_recv(T data);


Node<T>* Tree<T>::recv(Node<T>* node, vector<T>& ino, T data) {

}

Node<T>* Tree<T>::successor_recv(T data) {
    vector<T> ino;
    return recv()
}

int main() { run_tests(); return 0; }