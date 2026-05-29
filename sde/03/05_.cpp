#include <algorithm>
using namespace std;

int uniquePaths(int m, int n) {
  if (m <= 0 || n <= 0) return 0;

  int totalMoves = m+n-2;
  int choose = min(m-1, n-1);

  long long res=1;
  for (int i=1; i<=choose; i++) {
    res=res*(totalMoves-choose+i)/i;
  }
  return res;
}

#include "test/05.h"
int main() {
  run_tests("Sol", uniquePaths);
  print_report();
  return 0;
}
