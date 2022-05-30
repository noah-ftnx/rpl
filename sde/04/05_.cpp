int subarraysXorBF(vector<int> &arr, int x) {
  const int N = (int) arr.size();
  int cnt=0;
  for (int i=0; i<N; i++) {
    int num=0;
    for (int j=i; j<N; j++) {
      num=num xor arr[j];
      if (num==x) cnt++;
    }
  }
  return cnt;
}


int subarraysXor(vector<int> &arr, int x) {
  // 4, 2, 2, 6, 4 x:6
  // 4,2
  // 4,2,2,6
  // 6
  // 4,2,2,6,4
  // answer: 4
  const int N = (int) arr.size();
  int cnt=0;
  int xpr=0; // prefix xor
  unordered_map<int, int> mp;

  for (int i=0; i<N; i++) {
    xpr=xpr^arr[i];
    // elements so far match x
    if (xpr==x) cnt++;

    // there might be more subarrays:

    int y = xpr^x;
    if (mp.count(y)) {
      cnt+=mp[y];
      mp[y]=mp[y]+1; // increment
    } else {
      mp.insert({y, 1}); // init
    }
  }
  return cnt;
}