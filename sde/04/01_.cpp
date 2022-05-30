vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> mp;

  const int N = nums.size();
  for (int i=0; i<N; i++) {
    if (mp.count(nums[i])>0) { // remainder exists...... foudn it
      return {i, mp[nums[i]]};
    } else {
      mp.insert({target-nums[i], i});
    }
  }

  return {};
}