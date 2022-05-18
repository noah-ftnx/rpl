#include <vector>
#include <climits>
using namespace std;

int BF(int i, int x, vector<int> &num) {
  const int N = (int) num.size();
  // base cases:
  if (i==N) return 0; // no more elements

  int mx = INT_MIN;
  int pmx = INT_MIN;
  for (int p=i; p<min(N, i+x); p++) { // try valid partitions
    pmx=max(pmx, num[p]);
    const int len = p-i+1;
    int sum=(len*pmx) + BF(p+1, x, num);
    mx=max(mx, sum);
  }
  return mx;
}

int minimumElementsBF(vector<int> &num, int x) {
  return BF(0, x, num);
}



int MMZ(int i, int x, vector<int> &num, vector<int> &dp) {
  const int N = (int) num.size();
  // base cases:
  if (i==N) return 0; // no more elements

  if (dp[i]!=-1) return dp[i];

  int mx = INT_MIN;
  int pmx = INT_MIN;
  for (int p=i; p<min(N, i+x); p++) { // try valid partitions
    pmx=max(pmx, num[p]);
    const int len = p-i+1;
    int sum=(len*pmx) + MMZ(p+1, x, num, dp);
    mx=max(mx, sum);
  }
  return dp[i]=mx;
}

int minimumElementsMMZ(vector<int> &num, int x) {
  const int N = (int) num.size();
  vector<int> dp(N+1, -1);
  return MMZ(0, x, num, dp);
}



int minimumElementsBU(vector<int> &num, int x) {
  const int N = (int) num.size();
  vector<int> dp(N+1, 0);

  // base cases:
  // i==N: 0 // no more elements

  for (int i=N-1; i>=0; i--) {
    int mx = INT_MIN;
    int pmx = INT_MIN;
    for (int p=i; p<min(N, i+x); p++) { // try valid partitions
      pmx=max(pmx, num[p]);
      const int len = p-i+1;
      int sum=(len*pmx) + dp[p+1];
      mx=max(mx, sum);
    }
    dp[i]=mx;
  }
  return dp[0];
}



#include "test/dp054.h"
int main() {
  run_tests("BF", minimumElementsBF);
  run_tests("MMZ", minimumElementsMMZ);
  run_tests("BU", minimumElementsBU);
  // run_tests("OPT", minimumElementsBU);

  print_report();
  return 0;
}