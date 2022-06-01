int trap(vector<int>& height) {
  const int N = height.size();
  if (N<=2) return 0;

  int l=0, r=N-1;
  int maxL=height[l];
  int maxR=height[r];
  int sum=0;

  while (l<r) {
    if (height[l]<= height[r]) { // pick left
      maxL=max(maxL, height[l]); // max left wall
      sum+=maxL-height[l];
      l++;
    } else { // pick right
      maxR=max(maxR, height[r]);
      sum+=maxR-height[r];
      r--;
    }
  }
  return sum;
}
