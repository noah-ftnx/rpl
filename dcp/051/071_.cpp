#include <random>
using namespace std;

int rand7() {
  return (rand()%7)+1;
}

int rand5() {
  int n1 = rand7();
  int n2 = rand7();

  while (true) {
    int num = (n1*7)+n2;
    if (num == 56) {
      continue;
    }
    return (num%5)+1;
  }
}



#include "test/071.h"
int main() { run_tests(); return 0; }