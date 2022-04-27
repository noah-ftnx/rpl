
int print_all_subsequences(vector<int> input, int K) {
  if (K <=0 || input <=0) return 0;
  if (K > input * input) return 0;

  int res=0;
  for (int i=0; i< input; i++) {
    if (K % (i+1) == 0) { // divisible
      if (K / (i+1) <= input) res++;
    }
  }

  return res;
}



#include "test/074.h"
int main() { run_tests(); return 0; }