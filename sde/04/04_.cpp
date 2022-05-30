int maxLenBF(vector<int>&A, int n) {
  int mx {};
  for (int i=0; i<n; i++) {
    int sum=A[i];
    for (int j=i+1; j<n; j++) {
      sum+=A[j];
      if (sum==0) mx=max(mx, j-i+1);
    }
  }
  return mx;
}


int maxLen(vector<int>&A, int n) {
  unordered_map<int, int> mp;
  int mx=0;

  // w/o using any elements we have a sum of zero
  // case: adding all nums from i to 0 have a zero sum.
  int sum=0, i=-1;
  mp.insert({sum, i});

  for (i=0; i<n; i++) {
    sum+=A[i]; // prefix sum

    if (mp.count(sum)) {
      // found a zero sum subarray
      int len = i-mp[sum];
      mx=max(mx, len);
    } else {
      mp.insert({sum, i});
    }
  }

  return mx;
}