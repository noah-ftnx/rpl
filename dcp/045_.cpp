#include <random>

int rand5() { return rand()%5+1; }

int rand7() {
  int rnum;
  while(true){
    rnum= 5*(rand5()-1) + rand5();
    if(rnum<=21) return rnum%7+1;
  }
}

int rand7_alt() {
  int r1=rand5(), r2 = rand5();
  if (r2 <= 3) return r1;
  else if (r2 == 4) {
    if (r1 <= 3) return 6;
    else return rand7();
  } else {  // r2 == 5
    if (r1 <= 3) return 7;
    else return rand7();
  }
}



#include "test/045.h"
int main() { run_tests(); return 0; }
