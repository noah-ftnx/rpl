#include <cstdlib>

#include <iostream>
using namespace std;
double monte_carlo(int N) {
  double pi;
  int points=0, points_in_circle=0;

  for (int i=0; i<N; i++) {
    // random point in square: values are from 0 to 1
    double x = (double) (rand()%(N+1))/N;
    double y = (double) (rand()%(N+1))/N;
    points++;

    double dist = x*x + y*y;
    if (dist < 1) points_in_circle++;

    pi = 4.0 * points_in_circle / points;
  }

  return pi;
}



#include "test/014.h"
int main() { run_tests(); return 0; }