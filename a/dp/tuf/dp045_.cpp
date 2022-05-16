#include <vector>
#include <string>
using namespace std;

int longestStrChain(vector<string> &arr) {
  auto cmpAscSize = [](string &a, string &b) -> bool {
    return a.size() < b.size(); // ASC by str size
  };
  auto isValid = [](string cur, string prev) -> bool {
    const int P = (int) prev.size();
    // b is smaller by 1 char

    // if we have a diff >1 we break: no need to continue + OOB check
    int diff=0;
    for (int i=0; diff<2 && i<P; i++) {
      if (cur[i+diff]==prev[i]) continue; // advance both
      else { // they differ
        diff++; // next time, cur will skip this char
      }
    }

    // last char will be the difference (not checked in loop)
    if (diff==0) return true;
    // if there was a difference, then it must be 1
    else if (diff==1) return true;

    return false;
  };

  if (arr.empty()) return 0;
  const int N = (int) arr.size();

  sort(arr.begin(), arr.end(), cmpAscSize);
  vector<int> cnt(N, 1); // each str is longest just by itself

  int mx=1;
  for (int i=0; i<N; i++) {
    const int S = (int) arr[i].size();
    for (int prev=i-1; prev>=0; prev--) {
      const int P = (int) arr[prev].size();
      if (S==P) continue; // ignore same size (won't be a LSC)
      if (S-P!=1) break; // must have 1 size diff

      if (isValid(arr[i], arr[prev])) {
        if (cnt[prev]+1 >cnt[i]) {
          cnt[i]=cnt[prev]+1;
        }
      }
    } // for
    mx=max(mx, cnt[i]);
  }
  return mx;
}




#include "test/dp045.h"
int main() {
  run_tests("DP", longestStrChain);

  print_report();
  return 0;
}