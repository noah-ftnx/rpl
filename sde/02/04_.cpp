#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
  const int N = (int) nums.size();
  for (int i=0; i<N; i++) {
    // index marked negative: ret answer
    if (nums[abs(nums[i])-1]<0) return abs(nums[i]);

    // marks the index as negative
    nums[abs(nums[i])-1]*=-1;
  }
  return -1;
}

#include "test/04.h"
int main() {
  run_tests("Sol", findDuplicate);

  print_report();
  return 0;
}