
// TEMPLATE
struct Tree {

  Tree(T value);
  void add(const vector<T>& data, const string& path); // given

  void query_successors(deque<int>& query, deque<int>& answer);

};



#include "test/12.h"
int main() { run_tests(); return 0; }