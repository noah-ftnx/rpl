
bool partitioned_subsetBF(vector<int> input);

bool partitioned_subsetTD(vector<int> input);

bool partitioned_subsetBU(vector<int> input);

bool partitioned_subsetOPT(vector<int> input);



#include "test/060.h"
int main() {
  run_tests("BF", partitioned_subsetBF);
  // run_tests("MMZ", partitioned_subsetTD);
  // run_tests("BU", partitioned_subsetBU);
  // run_tests("OPT", partitioned_subsetOPT);

  print_errors();
  return 0;
}