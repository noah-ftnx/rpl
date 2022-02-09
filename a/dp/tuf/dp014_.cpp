#include <vector>
using namespace std;

bool BF(const vector<int>& input, int i, int target) {
  if (target==0) return true;
  else if (i==0) return input[0]==target;

  const int num=input[i];
  if (target>= num && BF(input, i-1, target-num)) return true;
  else return BF(input, i-1, target);
}

bool subset_sumBF(vector<int> input, int k) {
  if (input.empty()) return k==0;
  return BF(input, input.size()-1, k);
}


bool TD(const vector<int>& input, int i, int target, vector<vector<int>>& mmz) {
  if (target==0) return true;
  else if (i==0) return input[0]==target;
  else if(mmz[i][target]!=-1) return (bool) mmz[i][target];

  const int num=input[i];
  bool res;
  if (target>= num)  {
    res=TD(input, i-1, target-num, mmz);
  }
  if (!res ) res=TD(input, i-1, target, mmz);

  mmz[i][target]=res;
  return res;
}

bool subset_sumTD(vector<int> input, int k) {
  if (input.empty()) return k==0;
  vector<vector<int>> mmz(input.size(), vector<int>(k+1, -1));
  return TD(input, input.size()-1, k, mmz);
}

bool subset_sumBU(vector<int> input, int k) {
  if (input.empty()) return k==0;

  vector<vector<bool>> dp(input.size(), vector<bool>(k+1, false));

  // target k is 0: everything is accepted
  for (int i=0; i<input.size(); i++) dp[i][0]=true;

  // when index is 0, and we match the targe k, it's also true
  dp[0][input[0]]=true;

  for (int i=1; i<input.size(); i++) {
    for (int target=1; target<=k; target++) {
     const int num=input[i];
     bool res;
     if (target>=num) {
       res = dp[i-1][target-num];
     }
     if (!res) res=dp[i-1][target];

     dp[i][target]=res;
    }
  }

  // what we call the function as?
  return dp[input.size()-1][k];
}


bool subset_sumOPT(vector<int> input, int k) {
  if (input.empty()) return k==0;

  // vector<vector<bool>> dp(input.size(), vector<bool>(k+1, false));
  vector<bool> prev(k+1, false);
  vector<bool> cur(k+1, false);

  // replicate this each time
  // target k is 0: everything is accepted
  // for (int i=0; i<input.size(); i++) dp[i][0]=true;

  cur[0]=true;
  // dp[0][input[0]]=true;
  cur[input[0]]=true;

  for (int i=1; i<input.size(); i++) {
    swap(cur, prev);
    for (int target=1; target<=k; target++) {
      const int num=input[i];
      bool res;
      if (target>=num) {
        res = prev[target-num];
      }
      if (!res) res=prev[target];

      cur[target]=res;
    }
  }

  // what we call the function as?
  return cur[k];
}


#include "test/dp014.h"
int main() {
  run_tests("BF", subset_sumBF);
  run_tests("MMZ", subset_sumTD);
  run_tests("BU", subset_sumBU);
  run_tests("OPT", subset_sumOPT);

  print_errors();
  return 0;
}