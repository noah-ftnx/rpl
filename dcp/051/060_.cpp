#include <vector>
using namespace std;

bool BF(vector<int> input, int i, int k) {
  if (k==0) return true;
  else if (i==0) return k==input[0];

  const int num=input[i];
  bool res;
  if (k>=num) res=BF(input, i-1, k-num);
  if (!res) res=BF(input, i-1, k);
  return res;
}

bool partitioned_subsetBF(vector<int> input) {
  if (input.empty()) return true;
  int sum {};
  for (auto num: input) sum+=num;

  // cannot create 2 equal size partitions w/ odd sum
  if (sum%2!=0) return false;

  const int partitionSize=sum/2;
  return BF(input, (int) input.size()-1, partitionSize);
}


bool TD(vector<int> input, int i, int k, vector<vector<int>>& mmz) {
  if (k==0) return true;
  else if (i==0) return k==input[0];
  else if (mmz[i][k] != -1) return mmz[i][k];

  const int num=input[i];
  bool res {};
  if (k>=num) res=TD(input, i-1, k-num, mmz);
  if (!res) res=TD(input, i-1, k, mmz);
  mmz[i][k]=res;
  return res;
}

bool partitioned_subsetTD(vector<int> input) {
  if (input.empty()) return true;
  int sum {};
  for (auto num: input) sum+=num;

  // cannot create 2 equal size partitions w/ odd sum
  if (sum%2!=0) return false;

  const int partitionSize=sum/2;
  const int k = partitionSize;
  vector<vector<int>> mmz(input.size(), vector<int>(k+1, -1));
  return TD(input, (int) input.size()-1, k,mmz);
}

bool BU(vector<int> input, int k) {
  const int N = (int) input.size();
  vector<vector<bool>> dp(N, vector<bool>(k+1, false));
  // k is zero: all indices are true
  for (int i=0; i<N; i++) dp[i][0]=true;
  // last item: matches k
  if (input[0]<=k) dp[0][input[0]]=true;

  for (int i=1; i<N; i++) {
    for (int target=1; target<=k; target++) {
      bool res;
      const int num=input[i];
      if (target>=num) res=dp[i-1][target-num];
      if (!res) res=dp[i-1][target];
      dp[i][target]=res;
    }
  }
  return dp[N-1][k];
}


bool partitioned_subsetBU(vector<int> input) {
  if (input.empty()) return true;
  int sum {};
  for (auto num: input) sum+=num;

  // cannot create 2 equal size partitions w/ odd sum
  if (sum%2!=0) return false;
  const int partitionSize=sum/2;
  return BU(input, partitionSize);
}

bool OPT(vector<int> input, int k) {
  const int N = (int) input.size();
  vector<bool> cur(k+1, false);
  vector<bool> prev(k+1, false);

  cur[0]=true; // k is zero: accepted
  // last item: matches k
  if (input[0]<=k) cur[input[0]]=true;

  for (int i=1; i<N; i++) {
    swap(cur, prev);

    cur[0]=true; // k is zero: accepted
    for (int target=1; target<=k; target++) {
      const int num=input[i];
      bool res;
      if (target>=num) res=prev[target-num];
      if (!res) res=prev[target];
      cur[target]=res;
    }
  }
  return cur[k];
}

bool partitioned_subsetOPT(vector<int> input) {
  if (input.empty()) return true;
  int sum {};
  for (auto num: input) sum+=num;

  // cannot create 2 equal size partitions w/ odd sum
  if (sum%2!=0) return false;
  const int partitionSize=sum/2;
  return OPT(input, partitionSize);
}



#include "test/060.h"
int main() {
  run_tests("BF", partitioned_subsetBF);
  run_tests("MMZ", partitioned_subsetTD);
  run_tests("BU", partitioned_subsetBU);
  run_tests("OPT", partitioned_subsetOPT);

  print_errors();
  return 0;
}