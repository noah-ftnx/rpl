#include <vector>
#include <climits>
using namespace std;

int BF(int idx, int len, vector<int> &price) {
  if (idx==0) { // considering last size (1)
    return len*price[0];
  }

  // cut: allowing to re-cut at same sz
  int cut_sz=idx+1; // 1-based indexing (not using that..)
  int cut=INT_MIN;
  if (len-(cut_sz)>=0 && price[idx]!=0)
    cut=price[idx]+BF(idx, len-(idx+1), price);

  int dontCut=BF(idx-1, len, price);

  return max(cut, dontCut);
}

int cutRodBF(vector<int> &price, int n) {
  const int N = (int) price.size();
  return BF(N-1, n, price);
}



int MMZ(int idx, int len, vector<int> &price, vector<vector<int>> &dp) {
  int sz=idx+1; // 1-based indexing
  if (idx==0) { // considering last size (1)
    return len*price[0];
  } else if (dp[idx][len]!=-1) return dp[idx][len];

  // cut: allowing to re-cut at same sz
  int cut=INT_MIN;
  if (len-(idx+1)>=0)
    cut=price[idx]+MMZ(idx, len-(idx+1), price, dp);

  int dontCut=MMZ(idx-1, len, price, dp);

  return dp[idx][len]=max(cut, dontCut);
}

int cutRodMMZ(vector<int> &price, int n) {
  const int N = (int) price.size();
  vector<vector<int>> dp (N, vector<int>(n+1, -1));
  return MMZ(N-1, n, price, dp);
}



int cutRodBU(vector<int> &price, int n) {
  const int N = (int) price.size();
  const int rodLen=n;
  vector<vector<int>> dp (N, vector<int>(rodLen+2, 0));

  // base case: cut_sz 1
  for (int len=0; len<=rodLen; len++) dp[0][len]=len*price[0];

  for (int idx=1; idx<N; idx++) {
    int cut_sz=idx+1; // 1-based indexing
    for (int len=1; len<=rodLen; len++) {
      // cut: allowing to re-cut at same sz
      int cut=INT_MIN;
      if (len-cut_sz>=0)
        cut=price[idx]+dp[idx][len-cut_sz];

      int dontCut=dp[idx-1][len];

      dp[idx][len]=max(cut, dontCut);
    }
  }
  return dp[N-1][rodLen];
}



int cutRodOPT(vector<int> &price, int n) {
  const int N = (int) price.size();
  const int rodLen=n;
  vector<int> row(rodLen+1, 0);

  // base case: cut_sz 1
  for (int len=0; len<=rodLen; len++)
    row[len]=len*price[0];

  for (int idx=1; idx<n; idx++) {
    int cut_sz=idx+1; // 1-based indexing
    for (int len=0; len<=rodLen; len++) {
      // cut: allowing to re-cut at same sz
      int cut=INT_MIN;
      if (len-cut_sz>=0)
        cut=price[idx]+row[len-cut_sz];

      int dontCut=row[len];

      row[len]=max(cut, dontCut);
    }
  }

  return row[n];
}




#include "test/dp024.h"
int main() {
  run_tests("BF", cutRodBF);
  run_tests("MMZ", cutRodMMZ);
  run_tests("BU", cutRodBU);
  run_tests("OPT", cutRodOPT);

  // print_report();
  return 0;
}