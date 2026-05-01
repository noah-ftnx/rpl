int solve(int N, int X) {
  if (N <= 0 || X <= 0) return 0;
  if (X > N * N) return 0;

  int result=0;
  for (int i=1; i<=N; i++) {
    if (X % i == 0 && X / i <= N) result++;
  }

  return result;
}



#include "test/074.h"
int main() { run_tests(); return 0; }
