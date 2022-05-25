
bool searchMatrix(vector<vector<int>>& matrix, int target);



#include "test/01a.h"
int main() {
  run_tests("Sol", searchMatrix);

  print_report();
  return 0;
}