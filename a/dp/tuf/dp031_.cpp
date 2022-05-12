#include <string>
#include <vector>
using namespace std;

string shortestSupersequenceBU(string a, string b) {
  const int A = (int) a.size();
  const int B = (int) b.size();

  vector<vector<int>> dp(A+1, vector<int>(B+1, 0));

  // watch out for strings: convert to 0-based indexing

  for (int i=1; i<=A; i++) {
    for (int j=1; j<=B; j++) {
      if (a[i-1]==b[j-1]) {  // match
        dp[i][j]=1+dp[i-1][j-1];
      } else { // dont match
        int advi=dp[i-1][j];
        int advj=dp[i][j-1];
        dp[i][j]=max(advi, advj);
      }
    }
  }

  string res {};
  int i=A, j=B;
  while (i>0 && j>0) {
    if (a[i-1]==b[i-1]) { // match
      res=a[i-1]+res;
      i--; j--;
    } else { // dont match
      int up=dp[i-1][j];
      int left=dp[i][j-1];

      if (up > left) { // go up
        res=a[i-1]+res;
        i--;
      } else { // go left
        res=b[j-1]+res;
        j--;
      }
    }
  }

  // i,j are 1-based indexed. so we subtract before using
  while(i>0) {res=a[--i]+res;}
  while(j>0) {res=b[--j]+res;}

  return res;
}



#include "test/dp031.h"
int main() {
  // run_tests("BF", canYouMakeBF);
  // run_tests("MMZ", canYouMakeMMZ);
  run_tests("BU", shortestSupersequenceBU);
  // run_tests("OPT", canYouMakeOPT);

  print_report();
  return 0;
}