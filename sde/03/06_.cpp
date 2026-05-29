#include <vector>
using namespace std;

static int merge_count(vector<int> &nums, int l, int mid, int r, vector<int> &tmp) {
  int cnt = 0;
  int j = mid + 1;
  for (int i = l; i <= mid; i++) {
    while (j <= r && (long long) nums[i] > 2LL * nums[j]) j++;
    cnt += j - (mid + 1);
  }

  int i = l;
  j = mid + 1;
  int k = l;
  while (i <= mid && j <= r) {
    if (nums[i] <= nums[j]) tmp[k++] = nums[i++];
    else tmp[k++] = nums[j++];
  }
  while (i <= mid) tmp[k++] = nums[i++];
  while (j <= r) tmp[k++] = nums[j++];
  for (int p = l; p <= r; p++) nums[p] = tmp[p];
  return cnt;
}

static int sort_count(vector<int> &nums, int l, int r, vector<int> &tmp) {
  if (l >= r) return 0;
  int mid = l + (r - l) / 2;
  int cnt = sort_count(nums, l, mid, tmp);
  cnt += sort_count(nums, mid + 1, r, tmp);
  cnt += merge_count(nums, l, mid, r, tmp);
  return cnt;
}

int reversePairs(vector<int>& nums) {
  if (nums.empty()) return 0;
  vector<int> tmp(nums.size());
  return sort_count(nums, 0, (int) nums.size() - 1, tmp);
}

#include "test/06.h"
int main() {
  run_tests(reversePairs, "reversePairs");
  print_report();
  return 0;
}
