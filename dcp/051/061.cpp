
double pow(int x, int y);

double pow_fast(int x, int y);



#include "test/061.h"
int main() {
  run_tests("pow", pow);
  // run_tests("pow_fast", pow_fast);
  return 0;
}