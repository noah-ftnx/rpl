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



int BF(int i, int j, vector<int>& nums) {
  if (i>j) return -1e5;
  if (i==j) return nums[i]; // just the num itself

  int mid=(i+j)/2;
  int cres=nums[mid];
  int lres=BF(i, mid-1, nums); // just left
  int rres=BF(mid+1, j, nums); // just right

  // 3 results: all combined, or just left/right
  return max(cres+lres+rres, max(lres, rres));
}

int maxSubArrayDivideAndConquer(vector<int>& nums) { // BUGGY
  if (nums.empty()) return -1;

  const int N = nums.size();
  return BF(0, N-1, nums);
}



#include "test/04.h"
int main() {
  run_tests("BF", maxSubArrayBF);
  run_tests("Sol2", maxSubArray2);

  print_report();
  return 0;
}

