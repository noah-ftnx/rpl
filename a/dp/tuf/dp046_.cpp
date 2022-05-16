#include <vector>
using namespace std;

int longestBitonicSequence(vector<int>& arr, int n) {
  if (n<=1) return 0;

  // without copying arr: write mirror code for reverse!
  vector<int> rev=arr;
  reverse(rev.begin(), rev.end());
  vector<int> lis(n,1), lds(n,1);

  auto fill_cnt = [](int n, const vector<int> &vec, vector<int> &cnt) {
    for (int i=0; i<n; i++) {
      for (int prev=0; prev<i; prev++) {
        if (vec[i]>vec[prev] && cnt[prev]+1>cnt[i]) {
          cnt[i]=cnt[prev]+1;
        }
      }
    }
  };

  fill_cnt(n, arr, lis); // longest increasing
  fill_cnt(n, rev, lds); // longest decreasing

  int mx=1;
  for (int i=0; i<n; i++) {
    mx=max(mx, (lis[i]+lds[i]-1));
  }
  return mx;
}



#include "test/dp046.h"
int main() {
  run_tests("DP", longestBitonicSequence);

  print_report();
  return 0;
}