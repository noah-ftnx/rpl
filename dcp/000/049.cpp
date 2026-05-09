
// IMPLEMENT: max_sumBF
int max_sumBF(const vector<int>& input);

// IMPLEMENT: max_sumTD
int max_sumTD(const vector<int>& input);

// IMPLEMENT: max_sumBU
int max_sumBU(const vector<int>& input);

// IMPLEMENT: max_sumOPT
int max_sumOPT(const vector<int>& input);



#include "test/049.h"
int main() {
  run_tests("BF", max_sumBF);
  // run_tests("MMZ", max_sumTD);
  // run_tests("BU", max_sumBU);
  // run_tests("OPT", max_sumOPT);
  return 0;
}