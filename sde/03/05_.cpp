int uniquePaths(int m, int n) {
  const int P = m+n-2; // all the moves we have to do

  // we can either pick m-1, or n-1
  int r=m-1;
  double res=1;
  for (int i=1; i<=r; i++) {
    // P-r+i= 5-3+1 = 3
    // 5-3+2=4
    res=(res*(P-r+i))/(double) i;
  }
  return res;
}