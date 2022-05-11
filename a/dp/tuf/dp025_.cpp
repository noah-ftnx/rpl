#include <string>
#include <vector>
using namespace std;

int BF(int idxS, int idxT, string s, string t) {
  // base case: consumed either string
  if (idxS<0 | idxT<0) return 0;

  // matching
  if (s[idxS]==t[idxT]) return 1+BF(idxS-1, idxT-1, s, t);

  // not matching
  int adv1=BF(idxS-1, idxT, s, t);
  int adv2=BF(idxS, idxT-1, s, t);

  return max(adv1, adv2);
}

int lcsBF(string s, string t) {
  if (s.empty() || t.empty()) return 0;

  const int S = (int) s.size();
  const int T = (int) t.size();
  return BF(S-1, T-1, s, t);
}



int MMZ(int idxS, int idxT, string s, string t, vector<vector<int>> &dp) {
  // base case: consumed either string
  if (idxS<0 | idxT<0) return 0;
  else if (dp[idxS][idxT]!=-1) return dp[idxS][idxT];

  // matching
  if (s[idxS]==t[idxT])
    return dp[idxS][idxT]=1+MMZ(idxS-1, idxT-1, s, t, dp);

  // not matching
  int adv1=MMZ(idxS-1, idxT, s, t, dp);
  int adv2=MMZ(idxS, idxT-1, s, t, dp);

  return dp[idxS][idxT]=max(adv1, adv2);
}

int lcsMMZ(string s, string t) {
  if (s.empty() || t.empty()) return 0;

  const int S = (int) s.size();
  const int T = (int) t.size();
  vector<vector<int>> dp(S, vector<int>(T, -1));
  return MMZ(S-1, T-1, s, t, dp);
}



int lcsBU(string s, string t) {
  if (s.empty() || t.empty()) return 0;

  const int S = (int) s.size();
  const int T = (int) t.size();
  // shifting indices
  vector<vector<int>> dp(S+1, vector<int>(T+1, 0));

  for (int idxS=1; idxS<=S; idxS++) {
    for (int idxT=1; idxT<=T; idxT++) {
      if (s[idxS]==t[idxT]) {  // matching
        dp[idxS][idxT] = 1+dp[idxS-1][idxT-1];
      } else {  // not matching
        int adv1=dp[idxS-1][idxT];
        int adv2=dp[idxS][idxT-1];
        dp[idxS][idxT]=max(adv1, adv2);
      }
    }
  }
  return dp[S][T];
}



int lcsOPT(string s, string t) {
  if (s.empty() || t.empty()) return 0;

  const int S = (int) s.size();
  const int T = (int) t.size();

  // shifting indices
  vector<int> prev, cur(T+1, 0);

  for (int idxS=1; idxS<=S; idxS++) {
    prev=cur;
    for (int idxT=1; idxT<=T; idxT++) {
      if (s[idxS]==t[idxT]) {  // matching
        cur[idxT] = 1+prev[idxT-1];
      } else {  // not matching
        int adv1=prev[idxT];
        int adv2=cur[idxT-1];
        cur[idxT]=max(adv1, adv2);
      }
    }
  }
  return cur[T];
}



#include "test/dp025.h"
int main() {
  run_tests("BF", lcsBF);
  run_tests("MMZ", lcsMMZ);
  run_tests("BU", lcsBU);
  run_tests("OPT", lcsOPT);

  print_report();
  return 0;
}