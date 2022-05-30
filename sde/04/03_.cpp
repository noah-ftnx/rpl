int longestConsecutiveBF(vector<int>& nums) {
  if (nums.empty()) return 0;
  const int N = (int) nums.size();


  sort(nums.begin(), nums.end());
  int mx {1};
  int cnt{1};
  for (int i=1; i<N; i++) {
    // edge case: ignore equal numbers: 1,2,2,3
    if (nums[i-1]==nums[i]) continue;

    if (nums[i-1]+1==nums[i]) {
      cnt++;
      mx=max(mx, cnt);
    } else {
      cnt=1;
    }
  }
  return mx;
}



int longestConsecutiveOPT(vector<int>& nums) {
  int mx {};
  const int N = (int) nums.size();
  unordered_set<int> st;

  auto countConsecutive = [&] (int num) -> int {
    int cnt=0;

    while (st.count(num) >0) {
      cnt++;
      num++;
    }
    return cnt;
  };

  for(auto num: nums) st.insert(num);

  for (int i=0; i<N; i++) {
    // we want to start couting consecutive nums
    // from their min num, e.g.: 1,2,3, we want to start from 1
    // this will skip 2, or 3
    if (st.count(nums[i]-1)>0) continue;

    mx=max(mx, countConsecutive(nums[i]));
  }
  return mx;
}