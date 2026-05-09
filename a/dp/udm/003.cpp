
// IMPLEMENT: max_subarr_bf
int max_subarr_bf(const vector<int>& vec);
// IMPLEMENT: max_subarr_td
int max_subarr_td(const vector<int>& vec);
int max_subarr_bu(const vector<int>& vec)
// IMPLEMENT: sol
int sol(const vector<int>& vec);



#include "test/003.h"
int main() {
  run_tests("bf", max_subarr_bf);
  run_tests("td", max_subarr_td);
  run_tests("bu", max_subarr_bu);
  run_tests("sol", sol);
  return 0;
}