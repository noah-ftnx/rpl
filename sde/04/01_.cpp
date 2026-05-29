#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> mp;

  const int N = nums.size();
  for (int i=0; i<N; i++) {
    if (mp.count(nums[i])>0) {
      return {mp[nums[i]], i};
    } else {
      mp.insert({target-nums[i], i});
    }
  }

  return {};
}

#include "test/01.h"
int main() {
  run_tests(twoSum, "twoSum");
  print_report();
  return 0;
}
