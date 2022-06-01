vector<vector<int>> threeSumBad(vector<int>& nums) {
  auto getUniqueKey = [] (int a, int b, int c) {
    vector<int> v {a, b, c};
    sort(v.begin(), v.end());
    string key;
    for (int i: v) key+=to_string(i);
    return key;
  };

  unordered_map<int, int> mp; // num, occurences
  unordered_set<string> unq;

  // keep count of nums and occurences
  const int N = nums.size();
  for (int i=0; i<N; i++) {
    if (mp.count(nums[i])) {
      mp[nums[i]]=mp[nums[i]]+1;
    } else {
      mp.insert({nums[i], 1});
    }
  }

  vector<vector<int>> res;
  for (int i=0; i<N; i++) {
    mp[nums[i]]--; // allocate usage of i num
    for (int j=i+1; j<N; j++) {
      if (mp[nums[j]] >0) {

        mp[nums[j]]--; // allocate usage j num

        int tgt = -(nums[i]+nums[j]);
        // @i + @j + remainder = 0
        // remainder = -@i + -@j = -sum

        if (mp.count(tgt) && mp[tgt] >0) {
          // must add them sorted in a set, to avoid duplicates
          auto key = getUniqueKey(nums[i], nums[j], tgt);
          // if second is true, means added, else skipped (not unique)
          if (unq.insert(key).second) res.push_back({nums[i], nums[j], tgt});
        }

        mp[nums[j]]++; // de-allocate usage i num
      }
    }
    mp[nums[i]]++; // de-allocate usage i num
  }

  return res;
}



vector<vector<int>> threeSum(vector<int>& nums) {
  const int N = (int) nums.size();

  // idea of unique increments:
  // for each of the triplet indices (ie, i, l, or r)
  // I should only use a particular number once

  auto unqIncr = [&] (int& idx) { // unique increment
    int val=nums[idx]; // cur val
    while (idx+1<N && nums[idx+1]==val) idx++;  // ignore same values
    // do the unique increment
    idx++;
  };

  auto unqDecr = [&] (int& idx) {  // unique decrement
    int val=nums[idx]; // cur val
    while (idx-1>=0 && nums[idx-1]==val) idx--; // ignore same values
    // do the unique decrement
    idx--;
  };

  sort(nums.begin(), nums.end());
  vector<vector<int>> res;
  for (int i=0; i<N; unqIncr(i)) {
    // left and right, inclusive
    int l = i+1;
    int r = N-1;
    // search for 2 numbers
    while (l<r) {
      int sum = nums[i] + nums[l] + nums[r];
      if (sum>0) { // need smaller number
        unqDecr(r);
      } else if (sum<0) {
        unqIncr(l);
      } else {  // found solution
        res.push_back({nums[i], nums[l], nums[r]});
        unqIncr(l);
        unqDecr(r);
      }
    }
  }

  return res;
}

/*


N


 */