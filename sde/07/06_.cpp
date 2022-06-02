int findMaxConsecutiveOnes(vector<int>& nums) {
  if (nums.empty()) return 0;

  const int N = (int) nums.size();
  int mx=0;
  int ccnt=0;

  for (int i=0; i<N; i++) {
    // reset ccnt
    if (nums[i]!=1) { ccnt=0; continue; }

    mx=max(mx, ++ccnt);
  }

  return mx;
}
