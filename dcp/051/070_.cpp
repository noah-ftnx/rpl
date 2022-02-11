
int sum_of_digits(int num) {
  int sum {};

  while(num) {
    // 118: 8 -> 110 -> 11
    // 19 -> 10 -> 1
    int md =num%10;
    sum+=md;
    num-=md;
    num/=10;
  }
  return sum;
}

int perfect_nth(int n) {
  int i=-1;
  while(n) {
    // 19
    if (sum_of_digits(++i) == 10) n--;
  }
  return i;
}

int perfect_nth_fast(int n){
  int digits_sum = sum_of_digits(n);
  return n*10 + (10-digits_sum);
}



#include "test/070.h"
int main() { run_tests(); return 0; }