class Solution {
 public:

  int BF(int i, int amount, vector<int>& coins) {
    // base case:
    if (i==0) {
      // can we reach zero?
      if (amount%coins[0] != 0) return -1; // cant make change: high number

      return amount/coins[0];
    }

    // take a coin (allow to retake)
    int take=-1;
    if (amount-coins[i] >=0) { // taking does not exceed target
      int res=BF(i, amount-coins[i], coins);
      if (res!=-1) take=1+res;
    }

    // skip a coin
    int skip=BF(i-1, amount, coins);

    // handle invalid case:
    if (take==-1 && skip==-1) return -1; // both invalid
    else if (take==-1) return skip; // return the valid one
    else if (skip==-1) return take; // return the valid one
    else return min(take, skip);  // return the min one

  }

  int coinChange(vector<int>& coins, int amount) {
    const int N = (int) coins.size();
    return BF(N-1, amount, coins);
  }
};


int MMZ(int i, int amount, vector<int>& coins, vector<vector<int>> &dp) {
  // base case:
  if (i==0) {
    // can we reach zero?
    if (amount%coins[0] != 0) return -1; // cant make change: high number

    return amount/coins[0];
  }

  if (dp[i][amount]!=-1) return dp[i][amount];

  // take a coin (allow to retake)
  int take=-1;
  if (amount-coins[i] >=0) { // taking does not exceed target
    int res=MMZ(i, amount-coins[i], coins, dp);
    if (res!=-1) take=1+res;
  }

  // skip a coin
  int skip=MMZ(i-1, amount, coins, dp);

  // handle invalid case:
  if (take==-1 && skip==-1) return -1; // both invalid
  else if (take==-1) return skip; // return the valid one
  else if (skip==-1) return take; // return the valid one
  else return dp[i][amount]=min(take, skip);  // return the min one

}

int coinChangeMMZ(vector<int>& coins, int amount) {
  const int N = (int) coins.size();
  vector<vector<int>> dp(N, vector<int>(amount+1, -1));
  return MMZ(N-1, amount, coins, dp);
}


int coinChangeBU(vector<int>& coins, int amount) {
  const int N = (int) coins.size();
  vector<vector<int>> dp(N, vector<int>(amount+1, -1));

  dp[0][0]=0; // no coins and no amount
  for (int k=1; k<=amount; k++) {
    if (k%coins[0]==0) dp[0][k]=k/coins[0];
  }

  for (int i=1; i<N; i++) {
    for (int k=0; k<=amount; k++) {

      // take a coin (allow to retake)
      int take=-1;
      if (k-coins[i] >=0) { // taking does not exceed target
        int res=dp[i][k-coins[i]];
        if (res!=-1) take=1+res;
      }

      // skip a coin
      int skip=dp[i-1][k];

      // handle invalid case:
      if (take==-1 && skip==-1) dp[i][k]=-1; // both invalid
      else if (take==-1) dp[i][k]=skip; // return the valid one
      else if (skip==-1) dp[i][k]=take; // return the valid one
      else dp[i][k]=min(take, skip);  // return the min one
    }
  }

  return dp[N-1][amount];
}

int coinChangeOPT(vector<int>& coins, int amount) {
  const int N = (int) coins.size();
  vector<int> cur(amount+1, -1), prev;

  cur[0]=0; // no coins and no amount
  for (int k=1; k<=amount; k++) {
    if (k%coins[0]==0) cur[k]=k/coins[0];
  }

  for (int i=1; i<N; i++) {
    prev=cur;
    for (int k=0; k<=amount; k++) {

      // take a coin (allow to retake)
      int take=-1;
      if (k-coins[i] >=0) { // taking does not exceed target
        int res=cur[k-coins[i]];
        if (res!=-1) take=1+res;
      }

      // skip a coin
      int skip=prev[k];

      // handle invalid case:
      if (take==-1 && skip==-1) cur[k]=-1; // both invalid
      else if (take==-1) cur[k]=skip; // return the valid one
      else if (skip==-1) cur[k]=take; // return the valid one
      else cur[k]=min(take, skip);  // return the min one
    }
  }

  return cur[amount];
}