#include <vector>
using namespace std;

vector<int> divisibleSet(vector<int> &arr){
  if (arr.empty()) return {};

  const int N = (int) arr.size();
  sort(arr.begin(), arr.end()); // N log N
  vector<int> cnt(N, 1); // each num can divide itself
  vector<int> par(N, -1); // everyone par of itself

  int lastPar=0, mx=1;
  for (int i=0; i<N; i++) {
    // check prev nums to find max divisible
    for (int prev=i-1; prev>=0; prev--) {
      if (arr[i]%arr[prev]==0) {
        if (1+cnt[prev]>cnt[i]) {
          cnt[i]=1+cnt[prev];
          par[i]=prev;
          break; // on first divisible (max could get)
        }
      }
    }
    if (cnt[i]>mx) {  // update biggest div subset
      mx=cnt[i];
      lastPar=i;
    }
  }

  vector<int> res;
  while(lastPar!=-1) {
    // build subset
    res.insert(res.begin(), arr[lastPar]);
    lastPar=par[lastPar];
  }

  return res;
}



#include "test/dp044.h"
int main() {
  run_tests("DP", divisibleSet);

  print_report();
  return 0;
}