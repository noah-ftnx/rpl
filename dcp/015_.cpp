#include <stdint.h>
#include <cstdlib>
#include <vector>
#include <random>
using namespace std;

int get_random(int min, int max) {
  // obtain a random number from hardware
  std::random_device rd;
  // seed the generator
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(min, max); // define the range

  return distr(gen);
}

// assume we cannot use .size()
int pick_element(vector<int> stream) {
  srand(time(nullptr));
  uint64_t idx= 0;
  int element;
  for (auto n: stream) {
    if (idx == 0) element = n;
    else if ((rand()+1)%(idx)+1==1)  {
      element = n;
    }
    idx++;
  }

  return element;
}

#include "test/015.h"
int main() { run_tests(); return 0; }