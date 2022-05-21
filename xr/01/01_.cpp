#include <vector>
using namespace std;

vector<int> tnsBF(vector<int> nums, int K) {
  int N = (int) nums.size();
  for (int i=0; i<N; i++) {
    for (int j=i+1; j<N; j++) {
      if (nums[i]+nums[j]==K) return {nums[i], nums[j]};
    }
  }
  return {};
}


#include <unordered_set>
vector<int> tns2(vector<int> nums, int K) {
  unordered_set<int> st;
  const int N = nums.size();
  for (int i=0; i<N; i++) {
    if (st.count(nums[i])>=1) return { nums[i], K-nums[i] };
    else {
      // add that is missing to get K
      st.insert(K-nums[i]);
    }
  }
  return {};
}


vector<int> tns3(vector<int> nums, int K) {
  // 1, 3, 5, 7, 10
  sort(nums.begin(), nums.end()); // n logn
  const int N = nums.size();
  int left=0, right=N-1;

  while (left<right) {
    int sum = nums[left]+nums[right];
    if (sum==K) return {nums[left], nums[right]};
    else {
      if (sum < K) { // need higher sum
        left++;
      } else { // need lower sum
        right--;
      }
    }
  }
  return {};
}


#include "test/01.h"
int main() {
  run_tests("BF", tnsBF);
  run_tests("Sol2", tns2);
  run_tests("Sol3", tns3);

  print_report();
  return 0;
}
