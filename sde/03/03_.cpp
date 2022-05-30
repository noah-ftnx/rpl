int majorityElement(vector<int>& nums) {
  const int N = (int) nums.size();

  int limit = N/2;
  int cnt=0;
  int num=INT_MIN;

  for (int i=0; i<N; i++) {
    if (cnt==0) {
      num=nums[i];
    }

    if (nums[i]==num) cnt++;
    else cnt--;
  }
  return num;
}