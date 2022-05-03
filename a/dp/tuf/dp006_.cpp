#include <vector>
using namespace std;

int BF(vector<int>& nums, int i) {

  // base cases:
  if (i==0) return nums[0];
  else if (i<0) return 0; // OOB


  // case 1: rob this house
  int left=nums[i]+BF(nums, i-2);

  // case 2: don't rob
  int right=BF(nums, i-1);

  return max(left, right);
}

int robBF(vector<int>& nums) {
  if (nums.empty()) return 0;
  if (nums.size()==1) return nums[0];

  vector<int> v1 = nums, v2=nums;
  v1.erase(v1.begin());
  v2.pop_back();

  int woFirst = BF(v1, (int) v1.size()-1);
  int woLast = BF(v2, (int) v2.size()-1);
  return max(woFirst, woLast);
}



int MMZ(vector<int>& nums, int i, vector<int> &mmz) {
  // base cases:
  if (i==0) return nums[0];
  else if (i<0) return 0; // OOB
  else if (mmz[i]!=-1) return mmz[i];

  // case 1: rob this house
  int left=nums[i]+MMZ(nums, i-2, mmz);

  // case 2: don't rob
  int right=MMZ(nums, i-1, mmz);

  return mmz[i]=max(left, right);
}

int robMMZ(vector<int>& nums) {
  if (nums.empty()) return 0;
  if (nums.size()==1) return nums[0];

  vector<int> v1 = nums, v2=nums;
  v1.erase(v1.begin());
  v2.pop_back();

  vector<int> mmz1(v1.size()+1, -1),  mmz2(v1.size()+1,-1);
  int woFirst = MMZ(v1, (int) v1.size()-1, mmz1);
  int woLast = MMZ(v2, (int) v2.size()-1, mmz2);
  return max(woFirst, woLast);
}


int BU(vector<int>& nums) {
  const int N = (int) nums.size();
  vector<int> tab(N, 0);
  tab[0]=nums[0];

  for (int i=1; i<N; i++) {
    // case 1: rob this house
    int left=i-2>=0? nums[i]+tab[i-2] : nums[i];

    // case 2: don't rob
    int right=tab[i-1];

    tab[i]=max(left, right);
  }

  return tab[N-1];
}



int robBU(vector<int>& nums) {
  if (nums.empty()) return 0;
  if (nums.size()==1) return nums[0];

  vector<int> v1=nums, v2=nums;
  v1.erase(v1.begin());
  v2.pop_back();

  return max(BU(v2), BU(v1));
}



int OPT(vector<int>& nums) {
  const int N = (int) nums.size();
  int p2, p1=nums[0];
  int cur=p1;

  for (int i=1; i<N; i++) {
    // case 1: rob this house
    int left=i-2>=0? nums[i]+p2 : nums[i];
    // case 2: don't rob
    int right=p1;

    cur=max(left, right);
    p2=p1, p1=cur;
  }

  return cur;
}

int robOPT(vector<int>& nums) {
  if (nums.empty()) return 0;
  if (nums.size() == 1) return nums[0];

  vector<int> v1=nums, v2=nums;
  v1.erase(v1.begin());
  v2.pop_back();

  return max(OPT(v2), OPT(v1));
}



#include "test/dp006.h"
int main() {
  run_tests("BF", robBF);
  run_tests("TD", robMMZ);
  run_tests("BU", robBU);
  run_tests("OPT", robOPT);

  print_errors();
  return 0;
}