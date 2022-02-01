#include <vector>
using namespace std;
int find_num(vector<int> input) {
  vector<int> bits(32, 0);

  // count all the bits on each slot
  for (auto num: input) {
    for (int pos=0; pos<32; pos++) {
      // bits: 31, 30, .., 2, 1, 0
     bool bit_set = (num >> pos) & 1;
     // after 3 insertions, they will be zeroed out
     if (bit_set) bits[pos]=(bits[pos]+1) %3;
    }
  }

  // reconstruct the number
  int res {};
  for (int pos=0; pos<32; pos++) {
    if (bits[pos])
      res+=(1 << pos);
  }

  return res;
}



#include "test/040.h"
int main() { run_tests(); return 0; }