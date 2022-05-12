#include <string>
#include <vector>
using namespace std;

// 1-BASED INDICES
int BF(int i, int j, string &s, string &t) {
  // base cases:
  if (i==0) return j; // i (and maybe also j) were consumed add to s
  else if (j==0) return i;  // j consumed: del from s

  int replCost = s[i-1]!=t[j-1]; // if match: 0 cost

  int repl = replCost + BF(i-1, j-1, s, t);
  int del = 1 + BF(i-1, j, s, t);
  int add = 1 + BF(i, j-1, s, t);

  return min(repl, min(del, add));
}

int minDistanceBF(string s, string t) {
  const int S = (int) s.size();
  const int T = (int) t.size();

  return BF(S, T, s, t);
}



int MMZ(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
  // base cases:
  if (i==0) return j; // i (and maybe also j) were consumed add to s
  else if (j==0) return i;  // j consumed: del from s
  else if (dp[i][j]!=-1) return dp[i][j];

  int replCost = s[i-1]!=t[j-1]; // if match: 0 cost

  int repl = replCost + MMZ(i-1, j-1, s, t, dp);
  int del = 1 + MMZ(i-1, j, s, t, dp);
  int add = 1 + MMZ(i, j-1, s, t, dp);

  return dp[i][j]=min(repl, min(del, add));
}

int minDistanceMMZ(string s, string t) {
  const int S = (int) s.size();
  const int T = (int) t.size();

  vector<vector<int>> dp(S+1, vector<int>(T+1, -1));

  return MMZ(S, T, s, t, dp);
}



int minDistanceBU(string s, string t) {
  const int S = (int) s.size();
  const int T = (int) t.size();

  vector<vector<int>> dp(S+1, vector<int>(T+1, 0));

  // base cases:
  for (int j=0; j<=T; j++) dp[0][j]=j;  // i consumed: add to a
  for (int i=0; i<=S; i++) dp[i][0]=i;  // j consumed: del from a

  for (int i=1; i<=S; i++) {
    for (int j=1; j<=T; j++) {
      int replCost = s[i-1]!=t[j-1]; // if match: 0 cost

      int repl = replCost + dp[i-1][j-1];
      int del = 1 + dp[i-1][j];
      int add = 1 + dp[i][j-1];

      dp[i][j]=min(repl, min(del, add));
    }
  }
  return dp[S][T];
}



int minDistanceOPT(string s, string t) {
  const int S = (int) s.size();
  const int T = (int) t.size();

  vector<int> prev, cur(T+1, 0);
  // base cases:
  for (int j=0; j<=T; j++) cur[j]=j;  // i consumed: add to a


  for (int i=1; i<=S; i++) {
    prev=cur;
    cur[0]=i;
    for (int j=1; j<=T; j++) {
      int replCost = s[i-1]!=t[j-1]; // if match: 0 cost

      int repl = replCost + prev[j-1];
      int del = 1 + prev[j];
      int add = 1 + cur[j-1];

      cur[j]=min(repl, min(del, add));
    }
  }
  return cur[T];
}



#include "test/dp033.h"
int main() {
  run_tests("BF", minDistanceBF);
  run_tests("MMZ", minDistanceMMZ);
  run_tests("BU", minDistanceBU);
  run_tests("OPT", minDistanceOPT);
  // run_tests("OPT2", numDistinctOPT2);

  print_report();
  return 0;
}