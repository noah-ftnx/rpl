int functional_sum(int N) {
  if (N == 0) return 0;
  return N + functional_sum(N-1);
}

#include "test/01-func-sum.h"
int main() { run_tests(); return 0; }
