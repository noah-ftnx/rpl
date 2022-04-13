#include <cstdlib>

#include <random>
double monte_carlo(int N) {
  int circle_points=0;

  for (int i=0; i<N; i++) {
    double x = ((rand()%N)+1.0)/ (double)N;
    double y = ((rand()%N)+1.0)/ (double)N;
    // R=1:
    if (x*x + y*y < 1) circle_points++;
  }

  return 4*((double)circle_points/N);
}


#include "test/014.h"
int main() { run_tests(); return 0; }