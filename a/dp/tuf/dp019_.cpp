#include <vector>
using namespace std;

int BF(int idx, int capacity,
       vector<int> weight, vector<int> value) {
  if (idx==0) { // all items considered
    return capacity>=weight[idx] ? value[0] : 0;  // zero: cannot steal it
  }

  // we have to make sure that it does not get picked
  // setting to 0 also works for this particular example
  int skip=BF(idx-1, capacity, weight, value);
  int pick=INT_MIN;
  if (capacity-weight[idx]>=0) {
    pick=value[idx]+BF(idx-1, capacity-weight[idx], weight, value);
  }

  return max(pick, skip);
}

int knapsackBF(vector<int> weight, vector<int> value, int n, int maxWeight) {
  return BF(n-1, maxWeight, weight, value);
}




int MMZ(int idx, int capacity,
        vector<int> weight, vector<int> value, vector<vector<int>> &dp) {
  if (idx==0) { // all items considered
    return capacity>=weight[idx] ? value[0] : 0;  // zero: cannot steal it
  } else if (dp[idx][capacity]!=-1) return dp[idx][capacity];

  // we have to make sure that it does not get picked
  // setting to 0 also works for this particular example
  int skip=MMZ(idx-1, capacity, weight, value, dp);
  int pick=INT_MIN;
  if (capacity-weight[idx]>=0) {
    pick=value[idx]+MMZ(idx-1, capacity-weight[idx], weight, value, dp);
  }

  return dp[idx][capacity]=max(pick, skip);
}

int knapsackMMZ(vector<int> weight, vector<int> value, int n, int maxWeight) {
        vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
  return MMZ(n-1, maxWeight, weight, value, dp);
}



int knapsackBU(vector<int> weight, vector<int> value, int n, int maxWeight) {
  vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));

  // base case
  // could have inited cap to weight[0], and skip the 'if' in the loop
  for (int cap=0; cap<=maxWeight; cap++)
    if (cap>=weight[0])
      dp[0][cap]= value[0];

  for (int idx=1; idx<n; idx++) {
    for (int capacity=0; capacity<=maxWeight; capacity++) {
      int skip=dp[idx-1][capacity];
      int pick=INT_MIN;
      if (capacity-weight[idx]>=0) {
        pick=value[idx]+dp[idx-1][capacity-weight[idx]];
      }

      dp[idx][capacity]=max(pick, skip);
    }
  }
  return dp[n-1][maxWeight];
}



int knapsackOPT(vector<int> weight, vector<int> value, int n, int maxWeight) {
  vector<int> prev(maxWeight+1, 0);
  vector<int> cur(maxWeight+1, 0);

  // base case
  // could have inited cap to weight[0], and skip the 'if' in the loop
  for (int cap=0; cap<=maxWeight; cap++)
    if (cap>=weight[0])
      cur[cap]= value[0];

  for (int idx=1; idx<n; idx++) {
    prev=cur;
    for (int capacity=0; capacity<=maxWeight; capacity++) {
      int skip=prev[capacity];
      int pick=INT_MIN;
      if (capacity-weight[idx]>=0) {
        pick=value[idx]+prev[capacity-weight[idx]];
      }

      cur[capacity]=max(pick, skip);
    }
  }
  return cur[maxWeight];
}


int knapsackOPT2(vector<int> weight, vector<int> value, int n, int maxWeight) {
  vector<int> row(maxWeight+1, 0);

  // base case
  // could have inited cap to weight[0], and skip the 'if' in the loop
  for (int cap=0; cap<=maxWeight; cap++)
    if (cap>=weight[0])
      row[cap]= value[0];

  for (int idx=1; idx<n; idx++) {
    // we are never accessing anything from the left of each weight:
    // . . . . . . .
    //      cap->->  only dependencies are on the right
    // so if we start from the end, we can utilize a single row
    for (int capacity=maxWeight; capacity>=0; capacity--) {
      int skip=row[capacity];
      int pick=INT_MIN;
      if (capacity-weight[idx]>=0) {
        pick=value[idx]+row[capacity-weight[idx]];
      }

      row[capacity]=max(pick, skip);
    }
  }
  return row[maxWeight];
}



#include "test/dp019.h"
int main() {
  run_tests("BF", knapsackBF);
  run_tests("MMZ", knapsackMMZ);
  run_tests("BU", knapsackBU);
  run_tests("OPT", knapsackOPT);
  run_tests("OPT2", knapsackOPT2);

  print_report();
  return 0;
}