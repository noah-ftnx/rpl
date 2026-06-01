// status: passing
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  const int N = (int) nums.size();

  // idea of unique increments:
  // for each of the triplet indices (ie, i, l, or r)
  // I should only use a particular number once

  auto unqIncr = [&] (int& idx) { // unique increment
    int val=nums[idx]; // cur val
    while (idx+1<N && nums[idx+1]==val) idx++;  // ignore same values
    // do the unique increment
    idx++;
  };

  auto unqDecr = [&] (int& idx) {  // unique decrement
    int val=nums[idx]; // cur val
    while (idx-1>=0 && nums[idx-1]==val) idx--; // ignore same values
    // do the unique decrement
    idx--;
  };

  sort(nums.begin(), nums.end());
  vector<vector<int>> res;
  for (int i=0; i<N; unqIncr(i)) {
    // left and right, inclusive
    int l = i+1;
    int r = N-1;
    // search for 2 numbers
    while (l<r) {
      int sum = nums[i] + nums[l] + nums[r];
      if (sum>0) { // need smaller number
        unqDecr(r);
      } else if (sum<0) {
        unqIncr(l);
      } else {  // found solution
        res.push_back({nums[i], nums[l], nums[r]});
        unqIncr(l);
        unqDecr(r);
      }
    }
  }

  return res;
}

#include "test/03.h"
int main() {
  run_tests(threeSum, "threeSum");
  print_report();
  return 0;
}
