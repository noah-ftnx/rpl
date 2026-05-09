#include "test/15-full-tree.h"

// IMPLEMENT: Tree<T>::is_full
template <class T>
bool Tree<T>::is_full() {
    function<bool(Node<T>*)> f = [&](Node<T>* node) {
        if (!node) return true;
        
        bool L = node->left != nullptr;
        bool R = node->right != nullptr;
        if (L xor R) return false;
        
        if (!f(node->left)) return false;

        return f(node->right);
    };

    return f(root);
}

int main() { run_tests(); return 0; }
