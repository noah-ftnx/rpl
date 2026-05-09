#include <string>
#include <vector>
using namespace std;

struct WordFilter {
  WordFilter(vector<string>& words);
  // IMPLEMENT: f
  int f(string prefix, string suffix);
};



#include "test/09.h"
int main() { run_tests(); return 0; }
