// INCLUDES

struct Trie {

  void insert(string s);
  void autocomplete(string prefix, vector<string>& result);

};



#include "test/011.h"
int main() { run_tests(); return 0; }