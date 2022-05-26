int majorityElement(vector<int>& nums) {
  if (nums.empty()) return -1;

  const int N = nums.size();;
  int cnt=0, pick;

  for (int i=0; i<N; i++) {
    if (cnt==0) {
      pick=nums[i];
    }

    if (pick==nums[i]) {
      cnt++;
    } else {
      cnt--;
    }
  }
  return pick;
}