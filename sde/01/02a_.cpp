#include <vector>
using namespace std;

vector<int> lastRow(int N) {
  vector<int> fact(N+1, 1);

  // O(N): fill factorial array
  for (int i=2; i<=N; i++) {
    fact[i]=fact[i-1]*i;
  }

  vector<int> res (N, 1);
  for (int i=0; i<N; i++) {
    res[i]=fact[N-1]/ (fact[i]*fact[N-1-i]);
  }
  return res;
}

#include "test/02a.h"
int main() {

  run_tests("triangle", lastRow);

  print_report();
  return 0;
}
