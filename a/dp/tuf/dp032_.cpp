#include <vector>
#include <string>
using namespace std;

int BF(int i, int j, string &s, string &t) {
  // base cases:
  if (j==0) return 1; // a solution
  else if (i==0) return 0; // just i is 0, so no solution

  if (s[i-1]==t[j-1]) { // match
    // actually match it
    int match=BF(i-1, j-1, s, t);
    // ignore it
    int ignore=BF(i-1, j, s, t);
    return match + ignore;
  } else { // doesn't match
    return BF(i-1, j, s, t);
  }
}

int numDistinctBF(string s, string t)  {
  const int S = s.size();
  const int T = t.size();
  return BF(S, T, s, t);
}



int MMZ(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
  // base cases:
  if (j==0) return 1; // a solution
  else if (i==0) return 0; // just i is 0, so no solution
  else if (dp[i][j]!=-1) return dp[i][j];

  if (s[i-1]==t[j-1]) { // match
    // actually match it
    int match=MMZ(i-1, j-1, s, t, dp);
    // ignore it
    int ignore=MMZ(i-1, j, s, t, dp);
    return dp[i][j]=(match + ignore);
  } else { // doesn't match
    return dp[i][j]=MMZ(i-1, j, s, t, dp);
  }
}

int numDistinctMMZ(string s, string t)  {
  const int S = s.size();
  const int T = t.size();
  vector<vector<int>> dp (S+1, vector<int>(T+1, -1));
  return MMZ(S, T, s, t, dp);
}



int numDistinctBU(string s, string t)  {
  const int S = s.size();
  const int T = t.size();
  vector<vector<int>> dp (S+1, vector<int>(T+1, 0));

  // base cases:
  for (int i=0; i<=S; i++) dp[i][0]=1; // consumed t: solution
  // when i is 0: dp already inited to 0

  for (int i=1; i<=S; i++) {
    for (int j=1; j<=T; j++) {
      if (s[i-1]==t[j-1]) { // match
        // actually match it
        int match=dp[i-1][j-1];
        // ignore it
        int ignore=dp[i-1][j];
        dp[i][j]=(match + ignore);
      } else { // doesn't match
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  return dp[S][T];
}



int numDistinctOPT(string s, string t)  {
  const int S = s.size();
  const int T = t.size();
  vector<int> prev(T+1, 0), cur(T+1, 0);

  // base cases:
  prev[0]=cur[0]=1;  // consumed t: solution
  // when i is 0: dp already inited to 0

  for (int i=1; i<=S; i++) {
    prev=cur;
    for (int j=1; j<=T; j++) {
      if (s[i-1]==t[j-1]) { // match
        // actually match it
        int match=prev[j-1];
        // ignore it
        int ignore=prev[j];
        cur[j]=(match + ignore);
      } else { // doesn't match
        cur[j]=prev[j];
      }
    }
  }
  return cur[T];
}



int numDistinctOPT2(string s, string t)  {
  const int S = s.size();
  const int T = t.size();
  vector<int> row(T+1, 0);

  // base cases:
  row[0]=1;  // consumed t: solution
  // when i is 0: dp already inited to 0

  for (int i=1; i<=S; i++) {
    for (int j=T; j>=1; j--) {
      if (s[i-1]==t[j-1]) { // match
        int match=row[j-1];
        // ignore it
        int ignore=row[j];
        row[j]=(match + ignore);
      }
    }
  }
  return row[T];
}



#include "test/dp032.h"
int main() {
  run_tests("BF", numDistinctBF);
  run_tests("MMZ", numDistinctMMZ);
  run_tests("BU", numDistinctBU);
  run_tests("OPT", numDistinctOPT);
  run_tests("OPT2", numDistinctOPT2);

  print_report();
  return 0;
}