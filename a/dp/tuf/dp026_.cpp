#include <string>
#include <vector>
using namespace std;

void print_dp(string s, string t, const vector<vector<int>>& dp);

string NaiveBF(int i, int j, string s, string t) {
  if (i<0 || j<0) return "";

  if (s[i]==t[j]) { // matches
    return NaiveBF(i-1, j-1, s, t) + s[i];
  } else { // doesn't match
    string c1=NaiveBF(i-1, j, s, t);
    string c2=NaiveBF(i, j-1, s, t);
    return c1.size() > c2.size()? c1:c2;
  }
}

string lcsNaiveBF(string s, string t) {
  const int S = (int) s.size();
  const int T = (int) t.size();
  return NaiveBF(S-1, T-1, s, t);
}


string lcsBU(string s, string t) {
  const int S = (int) s.size();
  const int T = (int) t.size();

  vector<vector<int>> dp(S+1, vector<int>(T+1, 0));

  for (int i=1; i<=S; i++) {
    for (int j=1; j<=T; j++) {
      if (s[i-1]==t[j-1]) { // matches
        dp[i][j]=1+dp[i-1][j-1]; // diagonally (up-left)
      } else { // doesn't match
        int c1=dp[i-1][j]; // up
        int c2=dp[i][j-1]; // left
        dp[i][j]=max(c1, c2);
      }
    }
  }

  print_dp(s, t, dp);

  string res;
  int i=S, j=T;
  while (i>0 && j>0) {
    if (s[i-1]==t[j-1]) { // matches
      res=s[i-1] + res;  // put to solution
      i--; j--; // go diagonally up
    } else { // does not match
      int up=dp[i-1][j]; // up
      int left=dp[i][j-1]; // left
      if (up>left) i--; else j--;
    }
  }

  return res;
}


#include "test/dp026.h"
int main() {
  run_tests("NaiveBF", lcsNaiveBF);
  // run_tests("BF", lcsBF);
  // run_tests("MMZ", lcsMMZ);
  run_tests("BU", lcsBU);
  // run_tests("OPT", lcsOPT);

  print_report();
  return 0;
}