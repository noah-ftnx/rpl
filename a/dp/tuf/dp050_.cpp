#include <vector>
using namespace std;

int BF(int i, int j, vector<int> &cuts) {
  // base case: no further cut
  if (i>j) return 0;

  int mn=INT_MAX;
  for (int cut=i; cut<=j; cut++) {
    int chunk_len = cuts[j+1]-cuts[i-1];
    int cost = chunk_len + BF(i, cut-1, cuts) + BF(cut+1, j, cuts);
    mn=min(mn, cost);
  }
  return mn;
}

int costBF(int n, int c, vector<int> &cuts){
  cuts.insert(cuts.begin(), 0);
  cuts.push_back(n); // length of stock
  sort(cuts.begin(), cuts.end());
  // start by ignoring the additions (0, n)
  // CUTS 1, 3, 4, 5
  // 0  1       3   4   5       7
  // ---|-------|---|---|-------

  // c: is: c+1-1 (+1: addition, and -1 for zero based index)
  return BF(1, c, cuts);
}



int MMZ(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
  // base case: no further cut
  if (i>j) return 0;

  if (dp[i][j]!=-1) return dp[i][j];

  int mn=INT_MAX;
  for (int cut=i; cut<=j; cut++) {
    int chunk_len = cuts[j+1]-cuts[i-1];
    int cost = chunk_len + MMZ(i, cut-1, cuts, dp) + MMZ(cut+1, j, cuts, dp);
    mn=min(mn, cost);
  }
  return dp[i][j]=mn;
}

int costMMZ(int n, int c, vector<int> &cuts){
  cuts.insert(cuts.begin(), 0);
  cuts.push_back(n); // length of stock
  sort(cuts.begin(), cuts.end());
  // start by ignoring the additions (0, n)
  // CUTS 1, 3, 4, 5
  // 0  1       3   4   5       7
  // ---|-------|---|---|-------
  vector<vector<int>> dp(n, vector<int>(n, -1));
  return MMZ(1, c, cuts, dp);
}



int costBU(int n, int c, vector<int> &cuts){
  cuts.insert(cuts.begin(), 0);
  cuts.push_back(n); // length of stock
  sort(cuts.begin(), cuts.end());
  // start by ignoring the additions (0, n)
  // CUTS 1, 3, 4, 5
  // 0  1       3   4   5       7
  // ---|-------|---|---|-------
  vector<vector<int>> dp(c+2, vector<int>(c+2, 0));

  // base case: no further cut
  // i>j: 0

  for (int i=c; i>=1; i--) {
    for (int j=1; j<=c; j++) {
      if (i>j) continue;
      int mn=INT_MAX;
      for (int cut=i; cut<=j; cut++) {
        int chunk_len = cuts[j+1]-cuts[i-1];
        int cost = chunk_len + dp[i][cut-1]+dp[cut+1][j];
        mn=min(mn, cost);
      }
      dp[i][j]=mn;
    }
  }
  return dp[1][c];
}








#include "test/dp050.h"
int main() {
  run_tests("DP", costBF);
  run_tests("MMZ", costMMZ);
  run_tests("BU", costBU);
  // run_tests("OPT", costOPT);

  print_report();
  return 0;
}