#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
  int mx=0; // may do no transaction
  const int N = prices.size();
  if (N<=2) return 0;

  int buy=0; // bought at day 0

  for (int i=1; i<N; i++) {
    mx=max(mx, prices[i]-prices[buy]);
    if (prices[i] < prices[buy]) buy=i;
  }
  return mx;
}


#include "test/06.h"
int main() {
  run_tests("Sol", maxProfit);

  print_report();
  return 0;
}

