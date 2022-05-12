#include <vector>
using namespace std;

int lowestCantMake(vector<int> coins) {
  sort(coins.begin(), coins.end());
  int canMake=0;

  for (int coin: coins) {
    if (canMake+1>=coin) {
      canMake+=coin;
    } else { // bigger
      break;
    }
  }
  return canMake+1;
}



#include "test/001.h"
int main() { run_tests(); return 0; }