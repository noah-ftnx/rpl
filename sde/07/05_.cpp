int removeDuplicates(vector<int>& nums) {
  int wr=1;
  const int N = (int) nums.size();
  for (int i=1; i<N; i++) {
    if (nums[i] != nums[i-1]) {
      nums[wr++]=nums[i];
    }
  }
  nums.resize(wr);
  return wr;
}