#include <cmath>
#include <vector>
#include <climits>
using namespace std;

bool arbitrage(vector<vector<double>> rates) {
  const int N = rates.size();
  vector<vector<double>> G(N, vector<double>(N));

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      G[i][j]=-log(rates[i][j]);
    }
  }
  // apply bellman ford N times:
  // - N-1,
  // - an extra pass: check for neg cycles

  vector<double> dist(N, INT_MAX);
  dist[0]=0;

  auto relax_edges = [&](bool check_neg_cycle=false) -> bool {
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        if (dist[j] > dist[i] + G[i][j]) {
          dist[j]=dist[i]+G[i][j];
          if (check_neg_cycle) return true;
        }
      }
    }
    return false;
  };

  int relaxations=N-1;
  while(relaxations--) relax_edges();

  return relax_edges(true);
}



#include "test/032.h"
int main() { run_tests(); return 0; }