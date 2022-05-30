
vector<vector<int>> fourSumBF(vector<int>& nums, int target) {
  sort(nums.begin(), nums.end());
  const int N = nums.size();
  vector<vector<int>> res;

  auto inc = [&](int &l, int r) -> int {  // r: exclusive
    int val = nums[l];                    // cur val
    // ignore all same nums
    while (l + 1 < r && nums[l + 1] == val) l++;
    return l++;
  };

  for (int i = 0; i < N; inc(i, N)) {
    for (int j = i + 1; j < N; inc(j, N)) {
      for (int k = j + 1; k < N; inc(k, N)) {
        for (int m = k + 1; m < N; inc(m, N)) {
          int sum = nums[i] + nums[j] + nums[k] + nums[m];
          if (target == sum) {
            res.push_back({nums[i], nums[j], nums[k], nums[m]});
          }
        }
      }
    }
  }
  return res;
}




vector<vector<int>> fourSum(vector<int>& nums, int target) {
  sort(nums.begin(), nums.end());
  const int N = nums.size();
  vector<vector<int>> res;

  auto inc = [&] (int &l, int r) -> int { // r: exclusive
    int val = nums[l]; // cur val
    // ignore all same nums
    while(l+1<r && nums[l+1]==val) l++;
    return l++;
  };

  auto decr = [&] (int &idx, int lowLimit) -> int { // r: exclusive
    int val = nums[idx]; // cur right val
    // ignore all same nums
    while(idx-1> lowLimit && nums[idx-1]==val) idx--;
    return idx--;
  };


  for (int i=0; i<N; inc(i,N) ) {
    for (int j=i+1; j<N; inc(j,N)) {
      // can decide on last 2 nums w/ a single iteration
      // left and right on the array
      int l=j+1, r=N-1;
      while (l<r) {
        long long sum = ((long)nums[i]+nums[j]+nums[l]+nums[r]);
        bool overflow=false;
        if (sum > INT_MAX) overflow=true;

        if (!overflow && sum==(int)target) {
          res.push_back({nums[i],nums[j],nums[l],nums[r]});
          inc(l, r);
          decr(r, l);
          // 1 2 3 .... 5 6 7 20
        } else if (sum<target) { // need bigger num
          inc(l, r);
        } else { // need smaller num
          decr(r, l);
        }
      }
    }
  }
  return res;
}
