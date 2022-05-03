#include <vector>
using namespace std;

int BF(vector<int> &nums, int i) {
  // base cases
  if (i==0) return nums[0];
  else if (i<0) return 0; // out of bounds

  int left=nums[i]+ BF(nums, i-2);
  int right=BF(nums, i-1);
  return max(left, right);
}

int maximumNonAdjacentSumBF(vector<int> &nums){
  return BF(nums, (int) nums.size()-1);
}



int MMZ(vector<int> &nums, int i, vector<int> &mmz) {
  // base cases
  if (i==0) return nums[0];
  else if (i<0) return 0; // out of bounds
  else if (mmz[i]!=-1) return mmz[i];

  int left=nums[i]+ MMZ(nums, i-2, mmz);
  int right=MMZ(nums, i-1, mmz);
  return mmz[i]=max(left, right);
}

int maximumNonAdjacentSumMMZ(vector<int> &nums) {
  vector<int> mmz((int) nums.size(), -1);
  return MMZ(nums, (int) nums.size()-1, mmz);
}



int maximumNonAdjacentSumBU(vector<int> &nums){
  if (nums.empty()) return 0;
  vector<int> tab((int) nums.size(), 0);
  tab[0]=nums[0];

  const int N = (int) nums.size();
  for (int i=1; i<N; i++) {
    int left= i-2>=0? nums[i]+ tab[i-2] : nums[i]; // TRICKY
    int right=tab[i-1];
    tab[i]=max(left, right);
  }
  return tab[N-1];
}



int maximumNonAdjacentSumOPT(vector<int> &nums){
  if (nums.empty()) return 0;

  int p2{}, p1=nums[0];
  int cur=p1;

  const int N = (int) nums.size();
  for (int i=1; i<N; i++) {
    int left= i-2>=0? nums[i]+ p2: 0;
    int right=p1;
    cur=max(left, right);
    p2=p1, p1=cur;
  }
  return cur;
}



#include "test/dp005.h"
int main() {
  run_tests("BF", maximumNonAdjacentSumBF);
  run_tests("TD", maximumNonAdjacentSumMMZ);
  run_tests("BU", maximumNonAdjacentSumBU);
  run_tests("OPT", maximumNonAdjacentSumOPT);

  print_errors();
  return 0;
}