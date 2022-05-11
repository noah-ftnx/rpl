#include <string>
#include <vector>
using namespace std;

int BF(int i, int j, string s, string t) {
  if (i==0 || j==0) return 0; // base case: either str consumed

  if (s[i-1]==t[j-1]) { // matched
    return 1+BF(i-1, j-1, s, t);
  } else { // dont match
    int advi=BF(i-1, j, s, t);
    int advj=BF(i, j-1, s, t);
    return max(advi, advj);
  }
}

int minInsertionBF(string &s) {
  if (s.empty()) return 0;
  const int S = (int) s.size();
  string t=s;
  reverse(t.begin(), t.end());
  return S-BF(S, S, s, t);
}



int MMZ(int i, int j, string s, string t, vector<vector<int>> &dp) {
  if (i==0 || j==0) return 0; // base case: either str consumed
  else if (dp[i][j]!=-1) return dp[i][j];

  if (s[i-1]==t[j-1]) { // matched
    return dp[i][j]=(1+MMZ(i-1, j-1, s, t, dp));
  } else { // dont match
    int advi=MMZ(i-1, j, s, t, dp);
    int advj=MMZ(i, j-1, s, t, dp);
    return dp[i][j]=max(advi, advj);
  }
}

int minInsertionMMZ(string &s) {
  if (s.empty()) return 0;
  const int S = (int) s.size();
  string t=s;
  reverse(t.begin(), t.end());
  vector<vector<int>> dp(S+1, vector<int>(S+1, -1));
  return S-MMZ(S, S, s, t, dp);
}



int minInsertionBU(string &s) {
  if (s.empty()) return 0;
  const int S = (int) s.size();
  string t=s;
  reverse(t.begin(), t.end());

  vector<vector<int>> dp(S+1, vector<int>(S+1, 0));
  for (int i=1; i<=S; i++) {
    for (int j=1; j<=S; j++) {
      if (s[i-1]==t[j-1]) { // matched
        dp[i][j]=1+dp[i-1][j-1];
      } else { // dont match
        int advi=dp[i-1][j];
        int advj=dp[i][j-1];
        dp[i][j]=max(advi, advj);
      }
    }
  }
  return S-dp[S][S];
}



int minInsertionOPT(string &s) {
  if (s.empty()) return 0;
  const int S = (int) s.size();
  string t=s;
  reverse(t.begin(), t.end());

  vector<int> prev, cur(S+1, 0);
  for (int i=1; i<=S; i++) {
    prev=cur;
    for (int j=1; j<=S; j++) {
      if (s[i-1]==t[j-1]) { // matched
        cur[j]=1+prev[j-1];
      } else { // dont match
        int advi=prev[j];
        int advj=cur[j-1];
        cur[j]=max(advi, advj);
      }
    }
  }
  return S-cur[S];
}




#include "test/dp029.h"
int main() {
  run_tests("BF", minInsertionBF);
  run_tests("MMZ", minInsertionMMZ);
  run_tests("BU", minInsertionBU);
  run_tests("OPT", minInsertionOPT);

  print_report();
  return 0;
}