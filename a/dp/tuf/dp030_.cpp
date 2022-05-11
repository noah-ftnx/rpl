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

int canYouMakeBF(string &s, string &t) {
  if (s.empty() || t.empty()) return 0;
  const int S = (int) s.size();
  const int T = (int) t.size();

  int lcs=BF(S, T, s, t);
  return S-lcs + T-lcs;
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

int canYouMakeMMZ(string &s, string &t) {
  if (s.empty() || t.empty()) return 0;
  const int S = (int) s.size();
  const int T = (int) t.size();

  vector<vector<int>> dp(S+1, vector<int>(T+1, -1));
  int lcs=MMZ(S, T, s, t, dp);
  return S-lcs + T-lcs;
}



int canYouMakeBU(string &s, string &t) {
  if (s.empty() || t.empty()) return 0;
  const int S = (int) s.size();
  const int T = (int) t.size();

  vector<vector<int>> dp(S+1, vector<int>(T+1, 0));
  for (int i=1; i<=S; i++) {
    for (int j=1; j<=T; j++) {
      if (s[i-1]==t[j-1]) { // matched
        dp[i][j]=1+dp[i-1][j-1];
      } else { // dont match
        int advi=dp[i-1][j];
        int advj=dp[i][j-1];
        dp[i][j]=max(advi, advj);
      }
    }
  }

  int lcs=dp[S][T];
  return S-lcs + T-lcs;
}



int canYouMakeOPT(string &s, string &t) {
  if (s.empty() || t.empty()) return 0;
  const int S = (int) s.size();
  const int T = (int) t.size();

  vector<int> prev, cur(T+1, 0);
  for (int i=1; i<=S; i++) {
    prev=cur;
    for (int j=1; j<=T; j++) {
      if (s[i-1]==t[j-1]) { // matched
        cur[j]=1+prev[j-1];
      } else { // dont match
        int advi=prev[j];
        int advj=cur[j-1];
        cur[j]=max(advi, advj);
      }
    }
  }

  int lcs=cur[T];
  return S-lcs + T-lcs;
}



#include "test/dp030.h"
int main() {
  run_tests("BF", canYouMakeBF);
  run_tests("MMZ", canYouMakeMMZ);
  run_tests("BU", canYouMakeBU);
  run_tests("OPT", canYouMakeOPT);

  print_report();
  return 0;
}