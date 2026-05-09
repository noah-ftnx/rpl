#include <string>
using namespace std;

struct Trie {
  // IMPLEMENT: insert
  void insert(string s);
  // IMPLEMENT: suffix_exists
  bool suffix_exists(string suffix);
};



#include "test/05.h"
int main() { run_tests(); return 0; }
