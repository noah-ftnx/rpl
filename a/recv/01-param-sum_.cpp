void sum_recv(int i, int N, int &sum) {
  if (i > N) return;
  sum += i;
  sum_recv(i+1, N, sum);
}

int parameterized_sum(int N) {
  int sum {};
  sum_recv(1, N, sum);
  return sum;
}

#include "test/01-param-sum.h"
int main() { run_tests(); return 0; }
