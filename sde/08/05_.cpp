#include <vector>
using namespace std;

int findMinimumCoins(int amount) {
  vector<int> coins {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  const int N = (int) coins.size();
  int sum=0;
  for (int i=N-1; i>=0; i--) {
    int coin=coins[i];
    if (amount>=coin) { // can take this coin
      int coinsTaken=amount/coin;
      sum+=coinsTaken;
      amount%=coin;
    }
  }

  if (amount>0) return -1;
  else return sum;
}