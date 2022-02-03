#include <vector>
using namespace std;

int max_profit(vector<int> stock) {
  if (stock.empty()) return 0;

  const int N=stock.size();
  int mx=0, mn_price=stock[0];
  for (int i=1; i<N; i++) {
    if (stock[i]<mn_price) {
      mn_price=stock[i];
    } else if(stock[i]-mn_price > mx) {
      mx=stock[i]-mn_price;
    }
  }
  return mx;
}



#include "test/047.h"
int main() { run_tests(); return 0; }