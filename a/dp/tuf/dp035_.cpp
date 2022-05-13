#include <vector>
using namespace std;

int maximumProfitOPT(vector<int> &prices) {
  const int P = (int) prices.size();
  if (P<2) return 0;
  int profit=0;
  int mn=prices[0];
  for (int i=1; i<P; i++) {
    profit=max(profit, prices[i]-mn);
    mn=min(mn, prices[i]);
  }
  return profit;
}


#include "test/dp035.h"
int main() {
  // run_tests("BF", maximumProfitBF);
  // run_tests("MMZ", maximumProfitMMZ);
  // run_tests("BU", maximumProfitBU);
  run_tests("OPT", maximumProfitOPT);

  print_report();
  return 0;
}