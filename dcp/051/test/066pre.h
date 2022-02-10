#ifndef RPL_DCP_051_TEST_066PRE_H_
#define RPL_DCP_051_TEST_066PRE_H_

#include <random>
#include <unistd.h>

bool _inited {};
double rand_0to1() {
  if (_inited) {
    srand(time(NULL)); _inited=true;
  }
  // usleep(200 * 1e3 + (rand()%100+10));
  return (double)rand() / ((double)RAND_MAX + 1);
}

bool toss_biased() {
  const double BIAS {0.6};
  return rand_0to1() > BIAS;
}

#endif  // RPL_DCP_051_TEST_066PRE_H_