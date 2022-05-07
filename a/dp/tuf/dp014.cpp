
bool subset_sumBF(vector<int> input, int k);

bool subset_sumTD(vector<int> input, int k);

bool subset_sumBU(vector<int> input, int k);

bool subset_sumOPT(vector<int> input, int k);



#include "test/dp014.h"
int main() {
  run_tests("BF", subset_sumBF);
  run_tests("MMZ", subset_sumTD);
  run_tests("BU", subset_sumBU);
  run_tests("OPT", subset_sumOPT);

  print_report();
  return 0;
}