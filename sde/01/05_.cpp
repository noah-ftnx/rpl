#include <vector>
using namespace std;

void DNQ(int l, int r, vector<int>& nums) {
  if (l>=r) return; // indices crossed: no more elements to sort

  int mid = (l+r)/2;

  DNQ(l, mid, nums);
  DNQ(mid+1, r, nums);

  // conquer: merge l and r

  const int sz = r-l+1;
  vector<int> tmp(sz);

  int a=l, b=mid+1, k=0;
  while (a<=mid && b<=r) {
    if (nums[a] <= nums[b]) {
      tmp[k++]=nums[a++];
    } else {
      tmp[k++]=nums[b++];
    }
  }

  // copy any remaining elements
  while (a<=mid) tmp[k++]=nums[a++];
  while (b<=r) tmp[k++]=nums[b++];

  // copy from tmp to nums
  k=0;
  while(l<=r) nums[l++]=tmp[k++];

}

void sortColorsDNQ(vector<int>& nums) {
  const int N = nums.size();

  DNQ(0, N-1, nums);
}



void sortColors2(vector<int>& nums) {
  int c0, c1, c2;
  c0=c1=c2=0;
  for (auto n: nums) {
    switch (n) {
      case 0: c0++; break;
      case 1: c1++; break;
      case 2: c2++; break;
    }
  }

// override with the correct num of 0s, 1s, and 2s
  const int N = nums.size();

// write 1s
  int i=0;
  while (c0--) nums[i++]=0;
  while (c1--) nums[i++]=1;
  while (c2--) nums[i++]=2;
}



void sortColors3(vector<int>& nums) {
  const int N = nums.size();
  int z=-1, t=N, i=0;
  while(i<t) {
    if (nums[i]==1) { i++;}
    else if (nums[i]==0) {
      // advance z before, and i right after
      swap(nums[++z], nums[i++]);
    } else { // nums is 2
      // advance t before, but don't advance i
      // we have to check again, as we might have swapped
      // with another 2, or a zero..
      swap(nums[--t], nums[i]);
    }
  }
}



#include "test/05.h"
int main() {
  run_tests("NDQ", sortColorsDNQ);
  run_tests("Sol2", sortColors2);
  run_tests("Sol3", sortColors3);

  print_report();
  return 0;
}

