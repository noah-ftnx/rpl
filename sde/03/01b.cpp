
bool searchMatrix(vector<vector<int>>& matrix, int target);



#include "test/01b.h"
int main() {
  run_tests("Sol", searchMatrix);

  print_report();
  return 0;
}