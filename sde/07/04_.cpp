int trapBF(vector<int>& height) {
  const int N = height.size();
  if (N<=2) return 0;

  int sum=0;
  for (int i=0; i<N; i++) {
    // max wall at left
    int mxL=-1;
    for (int j=0; j<=i; j++) mxL=max(mxL, height[j]);

    // max wall at right
    int mxR=-1;
    for (int j=i; j<N; j++) mxR=max(mxR, height[j]);

    int trapped = min(mxL, mxR) - height[i];
    sum+=trapped;
  }
  return sum;
}


int trapBetter(vector<int>& height) {
  const int N = height.size();
  if (N<=2) return 0;

  // calculate prefix max and suffix max
  vector<int> prefixMax(N), suffixMax(N);
  int mx=height[0];
  for (int i=0; i<N; i++) {
    mx=max(mx, height[i]);
    prefixMax[i]=mx;
  }

  mx=height[N-1];
  for (int i=N-1; i>=0; i--) {
    mx=max(mx, height[i]);
    suffixMax[i]=mx;
  }

  // compute trapped water
  int sum=0;
  for (int i=0; i<N; i++) {
    int trapped = min(prefixMax[i], suffixMax[i]) - height[i];
    sum+=trapped;
  }
  return sum;
}



int trapOPT(vector<int>& height) {
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
