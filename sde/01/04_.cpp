#include <vector>
#include <climits>
using namespace std;

int maxSubArrayBF(vector<int>& nums) {
  const int N = (int) nums.size();
  if (nums.empty()) return -1;
  int mx= nums[0]; // empty subarray
  for (int i=0; i<N; i++) {
    int sum={};
    for (int j=i; j<N; j++) {
      sum+=nums[j];
      mx=max(mx, sum);
    }
  }
  return mx;
}



int maxSubArray2(vector<int>& nums) {
  if (nums.empty()) return -1;

  int mx = nums[0];
  const int N = nums.size();
  int sum {};
  for (int i=0; i<N; i++) {
    sum+=nums[i]; // add a number
    mx=max(mx, sum);
    if (sum<0) sum=0; // wont find higher subarray carrying this
  }
  return mx;
}



#include "test/04.h"
int main() {
  run_tests("BF", maxSubArrayBF);
  run_tests("Sol2", maxSubArray2);
  // run_tests("BF2", maxSubArray2);

  print_report();
  return 0;
}

