#include <vector>
#include <climits>
using namespace std;

int maximumProfitOPT(vector<int> &prices) {
  int profit=0;
  int mn=prices[0];
  for (int i=1; i<prices.size(); i++) {
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