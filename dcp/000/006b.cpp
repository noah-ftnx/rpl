
struct List {
  // IMPLEMENT: push_back
  void push_back(int n);
};

// IMPLEMENT: merge_k_lists
List* merge_k_lists(vector<List*> lists);



#include "test/006b.h"
int main() { run_tests(); return 0; }