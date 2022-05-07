#include <vector>
using namespace std;

bool BF(vector<int> input, int i, int k) {
  if (k==0) return true;
  else if (i==0) return k==input[0];

  bool res;
  const int val = input[i];
  if (k>=val) res=BF(input, i-1, k-val);
  if (!res) res=BF(input, i-1, k);

  return res;
}

bool subset_sumBF(vector<int> input, int k) {
  if (input.empty()) return k==0;
  return BF(input, (int) input.size()-1, k);
}

bool TD(vector<int> input, int i, int k, vector<vector<int>>& mmz) {
  if (k==0) return true;
  else if (i==0) return k==input[0];
  else if(mmz[i][k]!=-1) return (bool) mmz[i][k];

  bool res;
  const int val = input[i];
  if (k>=val) res=TD(input, i-1, k-val, mmz);
  if (!res) res=TD(input, i-1, k, mmz);

  mmz[i][k]=res;
  return res;
}

bool subset_sumTD(vector<int> input, int k) {
  if (input.empty()) return k==0;
  vector<vector<int>> mmz(input.size(), vector<int>(k+1, -1));
  return TD(input, (int) input.size()-1, k, mmz);
}

bool subset_sumBU(vector<int> input, int k) {
  if (input.empty()) return k==0;
  vector<vector<bool>> dp(input.size(), vector<bool>(k+1, false));

  // k=0: reached target k
  for (int i=0; i<(int)input.size(); i++) dp[i][0]=true;
  // i=0: then first element must match k
  if (input[0] <=k) dp[0][input[0]]=true;

  for (int i=1; i<(int) input.size(); i++) {
    for (int target=1; target<=k; target++) {
      bool res;
      const int val = input[i];
      if (target>=val) res=dp[i-1][target-val];
      if (!res) res=dp[i-1][target];
      dp[i][target]=res;
    }
  }
  return dp[input.size()-1][k];
}

bool subset_sumOPT(vector<int> input, int k) {
  if (input.empty()) return k==0;
  vector<bool> cur(k+1, false);
  vector<bool> prev(k+1, false);

  cur[0]=true;
  if (input[0] <=k) cur[input[0]]=true;

  for (int i=1; i<(int) input.size(); i++) {
    swap(cur, prev);

    cur[0]=true;
    for (int target=1; target<=k; target++) {
      bool res;
      const int val = input[i];
      if (target>=val) res=prev[target-val];
      if (!res) res=prev[target];
      cur[target]=res;
    }
  }
  return cur[k];
}



#include "test/dp014.h"
int main() {
  run_tests("BF", subset_sumBF);
  run_tests("MMZ", subset_sumTD);
  run_tests("BU", subset_sumBU);
  run_tests("OPT", subset_sumOPT);

  print_report();
  return 0;
}