#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums) {
  if (nums.size() <=1) return;

  int stop_idx=-1;
  const int N = (int) nums.size();
  for (int i=N-2; i>=0; i--) {
    if (nums[i] < nums[i+1]) {
      stop_idx=i; break;
    }
  }

  // find element in stop_idx-N that is GT stop
  int replace_idx;
  if (stop_idx!=-1) {
    for (int i=N-1; i>=0; i--) {
      if (nums[i]>nums[stop_idx]) {
        replace_idx=i; break;
      }
    }
    swap(nums[stop_idx], nums[replace_idx]);
  }

  // reverse stop_idx-N
  reverse(nums.begin()+stop_idx+1, nums.end());
}



#include "test/03.h"
int main() {

  run_tests("nextPermutation", nextPermutation);

  print_report();
  return 0;
}