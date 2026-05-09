
// IMPLEMENT: max_passBF
int max_passBF(const vector<int>& v);
// IMPLEMENT: max_passTD
int max_passTD(const vector<int>& v);
// IMPLEMENT: max_passBU
int max_passBU(const vector<int>& v);
// IMPLEMENT: sol
int sol(const vector<int>& v);



#include "test/002.h"
int main() {
  run_tests("BF", max_passBF);
  run_tests("TD", max_passTD);
  run_tests("BU", max_passBU);
  run_tests("sol", sol);
  return 0;
}