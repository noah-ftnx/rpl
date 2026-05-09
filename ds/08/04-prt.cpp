#include <string>
#include <vector>
using namespace std;

struct Trie {
  // IMPLEMENT: insert
  void insert(string s);
  // IMPLEMENT: get_words
  vector<string> get_words();
};



#include "test/04.h"
int main() { run_tests(); return 0; }
