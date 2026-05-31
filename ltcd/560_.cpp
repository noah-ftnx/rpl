#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefix_count;
    prefix_count[0] = 1;

    int count = 0;
    int prefix_sum = 0;

    for (int num : nums) {
      prefix_sum += num;
      int need_to_remove = prefix_sum - k;
      count += prefix_count[need_to_remove];
      prefix_count[prefix_sum]++;
    }

    return count;
  }
};

#include "test/560.h"
int main() { run_tests(); return 0; }
