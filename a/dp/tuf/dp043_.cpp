#include <vector>
using namespace std;

int lengthOfLISBF_DP3(vector<int>& nums) {
  const int N = (int) nums.size();

  vector<int> vec;

  for (int i=0; i<N; i++) {
    // first element or greater element than last one
    if (i==0 || nums[i] > vec.back()) {
      vec.push_back(nums[i]);
    } else { // smaller element
      // find which one to replace:
      int j;
      for (j=0; j<=vec.size(); j++) {
        if (vec[j]>nums[i]) break;
      }
      vec[j]=nums[i];
    }
  }
  return vec.size();
}


int bsearch(vector<int>& vec, int el) {
  int left=0, right=vec.size()-1;
  int mid=0;
  while (left<right) {
    mid=(left+right)/2;
    // found: replace itself w/ the same num
    if (vec[mid]==el) return mid;
    else if (vec[mid]> el) { // search left
      right=mid-1;
    } else { // search right
      left=mid+1;
    }
  }
  // example 1:
  // 3:
  // 1 2 10
  // 3 must replace 10
  // example 2:
  // 1 4 10
  // 3 must replace 4

  // smaller mid element: must replace the next one
  if (vec[mid] < el) return mid+1;
  // mid element greater: must replace the mid element
  else return mid;
}

int lengthOfLISBF_DP4(vector<int>& nums) {
  const int N = (int) nums.size();

  vector<int> vec;

  for (int i=0; i<N; i++) {
    // first element or greater element than last one
    if (i==0 || nums[i] > vec.back()) {
      vec.push_back(nums[i]);
    } else { // smaller element
      // find which one to replace:
      int j=bsearch(vec, nums[i]);
      vec[j]=nums[i];

      // STL ALT
      // binary search: get first number that is >= that nums[i]
      // auto it = lower_bound(vec.begin(), vec.end(), nums[i]);
      // *it=nums[i];
    }
  }
  return vec.size();
}



#include "test/dp041.h"
int main() {
  run_tests("DP3", lengthOfLISBF_DP3);
  run_tests("DP4", lengthOfLISBF_DP4);

  print_report();
  return 0;
}