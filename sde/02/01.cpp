
void rotate(vector<vector<int>>& matrix);



#include "test/01.h"
int main() {
  run_tests("Sol", rotate);
  run_tests("Sol2", rotate2);

  print_report();
  return 0;
}