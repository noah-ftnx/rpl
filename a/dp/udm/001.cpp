
// IMPLEMENT: count_bf
uint64_t count_bf(int n);
// IMPLEMENT: count_td
uint64_t count_td(int n);
// IMPLEMENT: count_bu
uint64_t count_bu(int n);
// IMPLEMENT: sol
uint64_t sol(int n);



#include "test/001.h"
int main() {
  run_tests("BF", count_bf);
  run_tests("TD", count_td);
  run_tests("BU", count_bu);
  run_tests("sol", sol);
  return 0;
}