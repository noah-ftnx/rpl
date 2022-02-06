#ifndef RPL_DCP_051_TEST_051PRE_H_
#define RPL_DCP_051_TEST_051PRE_H_

#include <random>
#include <unistd.h>  // usleep

bool _init {};

void init_rand() {
  if (!_init) {
    srand(time(nullptr));
    _init=true;
  }
}

int randk(int k) {
  init_rand();
  usleep(200 * 1e3 + (rand()%100+10));
  return 1+(rand()%k);
}


#endif  // RPL_DCP_051_TEST_051PRE_H_
