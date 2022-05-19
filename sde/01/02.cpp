
vector<vector<int>> generate(int numRows);



#include "test/02.h"
int main() {

  run_tests("triangle", generate);

  print_report();
  return 0;
}
