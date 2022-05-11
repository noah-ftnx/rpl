#include <string>
#include <vector>
using namespace std;

int NaiveBF(int l, int r, string &s) {
  if (l>=r) {  // base case: examined all characters
    return l==r; // if equal: an extra char
  }

  if (s[l]==s[r]) {  // match
    return 2+NaiveBF(l+1, r-1, s); // close in
  } else {  // dont match
    int advL=NaiveBF(l+1, r, s);
    int advR=NaiveBF(l, r-1, s);
    return max(advL, advR);
  }
}

int longestPalindromeSubseqNaiveBF(string s) {
  return NaiveBF(0, s.size()-1, s);
}



int BF(int i, int j, string s, string t) {
  // base case:
  if (i==0 || j==0) return 0; // consumed all chars

  if (s[i-1]==t[j-1]) { // match
    return 1+BF(i-1, j-1, s, t);
  } else { // dont match
    int advS=BF(i-1, j, s, t);
    int advT=BF(i, j-1, s, t);
    return max(advS, advT);
  }
}

int longestPalindromeSubseqBF(string s) {
  const int S = (int) s.size();
  string rev=s;
  reverse(s.begin(), s.end());
  return BF(S, S, s, rev);
}



int MMZ(int i, int j, string s, string t, vector<vector<int>> &dp) {
  // base case:
  if (i==0 || j==0) return 0; // consumed all chars
  else if (dp[i][j] != -1) return dp[i][j];

  if (s[i-1]==t[j-1]) { // match
    return dp[i][j]=1+MMZ(i-1, j-1, s, t, dp);
  } else { // dont match
    int advS=MMZ(i-1, j, s, t, dp);
    int advT=MMZ(i, j-1, s, t, dp);
    return dp[i][j]=max(advS, advT);
  }
}

int longestPalindromeSubseqMMZ(string s) {
  const int S = (int) s.size();
  string rev=s;
  reverse(s.begin(), s.end());
  vector<vector<int>> dp(S+1, vector<int>(S+1, -1));
  return MMZ(S, S, s, rev, dp);
}



int longestPalindromeSubseqBU(string s) {
  const int S = (int) s.size();
  string t=s;
  reverse(t.begin(), t.end());
  vector<vector<int>> dp(S+1, vector<int>(S+1, 0));

  for (int i=1; i<=S; i++) {
    for (int j=1; j<=S; j++) {
      if (s[i-1]==t[j-1]) { // match
        dp[i][j]=1+dp[i-1][j-1];
      } else { // dont match
        int advS=dp[i-1][j];
        int advT=dp[i][j-1];
        dp[i][j]=max(advS, advT);
      }
    }
  }
  return dp[S][S];
}



int longestPalindromeSubseqOPT(string s) {
  const int S = (int) s.size();
  string t=s;
  reverse(t.begin(), t.end());
  vector<int> prev, cur(S+1, 0);

  for (int i=1; i<=S; i++) {
    prev=cur;
    for (int j=1; j<=S; j++) {
      if (s[i-1]==t[j-1]) { // match
        cur[j]=1+prev[j-1];
      } else { // dont match
        int advS=prev[j];
        int advT=cur[j-1];
        cur[j]=max(advS, advT);
      }
    }
  }
  return cur[S];
}



#include "test/dp028.h"
int main() {
  run_tests("NaiveBF", longetPalindromeSubseqNaiveBF);
  run_tests("BF", longestPalindromeSubseqBF);
  run_tests("MMZ", longestPalindromeSubseqMMZ);
  run_tests("BU", longestPalindromeSubseqBU);
  run_tests("OPT", longestPalindromeSubseqOPT);

  print_report();
  return 0;
}