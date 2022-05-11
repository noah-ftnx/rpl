#include <string>
#include <vector>
using namespace std;

int lcstrNaiveBF(string s, string t) {
  const int S =(int) s.size();
  const int T = (int) t.size();

  int mx=0;
  for (int i=0; i<S; i++) {
    for (int j=0; j<T; j++) {
      int matches=0;
      for (int k=j; k<T && s[i+matches]==t[k]; k++) { matches++; }
      mx=max(mx, matches);
    }
  }

  return mx;
}


int lcstrBU(string s, string t) {
  const int S = (int) s.size();
  const int T = (int) t.size();

  vector<vector<int>> dp(S+1, vector<int>(T+1, 0));
  int mx=0;
  for (int i=1; i<=S; i++) {
    for (int j=1; j<=T; j++) {
      if (s[i-1]==t[j-1]) {// matches
        dp[i][j]=1+dp[i-1][j-1];
        mx=max(mx, dp[i][j]);
      } else { // doesnt match
        dp[i][j]=0;
      }
    }
  }
  return mx;
}



#include "test/dp027.h"
int main() {
  run_tests("NaiveBF", lcstrNaiveBF);
  run_tests("BU", lcstrBU);

  print_report();
  return 0;
}