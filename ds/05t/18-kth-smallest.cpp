#include "test/18-kth-smallest.h"

// IMPLEMENT: Tree<T>::kth_smallest
optional<T> Tree<T>::kth_smallest(int k);

//
// k is 1-based:
// - k=1 => smallest
// - k=N => largest

int main() { run_tests(); return 0; }
