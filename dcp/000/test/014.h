#ifndef RPL_DCP_TEST_014_H_
#define RPL_DCP_TEST_014_H_

#include <iostream>
#include <iomanip>
using namespace std;
void test(int N) {
  double res = monte_carlo(N);
  bool wrong  = res - 3.14 > 1;
  cout << setw(3) << N << ": pi:" << res << (wrong? " (WRONG)":"") << endl;
}

void run_tests() {
  test(10000);
  test(10000000);

}


#endif  // RPL_DCP_TEST_014_H_
