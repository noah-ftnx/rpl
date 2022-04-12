#include <iostream>
#include <unistd.h>
using namespace std;

void add(int a, int b);

void schedule_way1(void* func, uint64_t ms) {
  usleep(ms*1e3);
  void (*function)(int, int) = (void (*)(int, int)) func;
  function(10, 5);
}

void schedule_way2(void (*function)(int, int), uint64_t ms) {
  usleep(ms*1e3);
  function(10, 5);
}

#include <functional>
void schedule_way3(std::function<void(int, int)> function, uint64_t ms) {
  usleep(ms*1e3);
  function(10, 5);
}

using fptr1 = decltype(add);
void schedule_way4(fptr1 function, uint64_t ms) {
  // sleep(1); // takes seconds
  usleep(ms*1e3);
  function(10, 5);
}



#include "test/010.h"
int main() { run_tests(); }