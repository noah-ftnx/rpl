
int solve(int N, int X) {
  if (X<=0 || N <=0) return 0;
  if (X > N*N) return 0;

  int res=0;
  for (int i=0; i<N; i++) {
    if (X % (i+1) == 0) { // divisible
      if (X / (i+1) <= N) res++;
    }
  }

  return res;
}



#include "test/074.h"
int main() { run_tests(); return 0; }