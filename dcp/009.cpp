
int sum_naBF(const vector<int>& vec);
int sum_naTD(const vector<int>& vec);
int sum_naBU(const vector<int>& v);
int sol(const vector<int>& v);



#include "test/009.h"
int main() {
  run_tests("BF", sum_naBF);
  run_tests("TD", sum_naTD);
  run_tests("BU", sum_naBU);
  run_tests("sol", sol);
  return 0;
}