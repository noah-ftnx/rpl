#include<cmath>
using namespace std;

double findNthRootOfMSTL(int n, long long m) {
  return pow((double)m, 1/(double)n);
}

double findNthRootOfM(int n, long long m) {
  long double low=1, high=m;

  long double mid;
  double accuracy = 1e-7;
  while(high-low >= accuracy) { // until accuracy is met
    // iii (3 bits)
    // 3+7 = 10 .. 10/2 = 5
    // 3+2=3+(7-3)/2=3+(4/2)=3+2=5
    // ((high-low)/2) + low
    mid= ((high-low)/2.0) + low; // (low+high)/2.0;

    long double res = pow(mid, n);

    if (res > m) { // need a smaller number
      high=mid;
    } else {  // need a bigger number
      low=mid;
    }
  }
  return mid;
}


#include "test/01.h"
int main() {
  run_tests("STL", findNthRootOfMSTL);
  run_tests("SOL", findNthRootOfM);

  print_report();
  return 0;
}