// INCLUDES

struct WordFilter {
  WordFilter(vector<string>& words);
  int f(string prefix, string suffix);
};



#include "test/09.h"
int main() { run_tests(); return 0; }