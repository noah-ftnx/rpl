vector<int> majorityElement(vector<int>& nums) {
  const int N = nums.size();
  const int limit = N/3;
  int c1=0,c2=0,n1=INT_MIN,n2=INT_MIN;
  vector<int> res;

  for (int i=0; i<N; i++) {
    // dont swap it directly. give it another change
    if (nums[i]==n1) c1++;
    else if (nums[i]==n2) c2++;
    else if (c1==0) { c1=1; n1=nums[i]; }
    else if (c2==0) { c2=1; n2=nums[i]; }
    else { c1--; c2--; }
  }


  c1=c2=0;
  for (int i=0; i<N; i++) {
    if (nums[i]==n1) c1++;
    else if (nums[i]==n2) c2++;
  }

  if (c1>limit) res.push_back(n1);
  if (c2>limit) res.push_back(n2);

  return res;
}