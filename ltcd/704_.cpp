#include <vector>
using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int L = 0;
    int R = nums.size()-1;

    while (L <= R) {
      int mid = L + (R-L)/2;
      if (nums[mid] == target) return mid;
      if (target > nums[mid])
        L = mid+1;
      else
        R = mid-1;
    }

    return -1;
  }
};

#include "test/704.h"
int main() { run_tests(); return 0; }
