bool toss_biased();  // GIVEN
#include "test/066pre.h"

bool toss() {
  while (true) {
    bool t1 = toss_biased();
    bool t2 = toss_biased();

    if (t1==t2) continue;

    return t2;
  }
}



#include "test/066.h"
int main() { run_tests(); return 0; }