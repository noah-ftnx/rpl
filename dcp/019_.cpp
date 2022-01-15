#include <vector>
using namespace std;

int paint_houses(vector<vector<int>> input){
  if (input.empty() || input[0].empty()) return -1;

  const int N = input.size();
  const int K = input[0].size();

  if (N>1 && K<2) return -1;  // more than 1 house, with not enough colors

  // H1: 2 5 1 5
  // H2: 1 0 3 2
  // H3: 1 1 2 3
  // H4: 4 2 3 1
  struct Min {
    int color;
    int cost = INT_MAX;
  };

  auto set_min = [] (int cost, int color, Min& m1, Min& m2) {
    if (cost < m1.cost) {
      m2=m1;
      m1.color=color;
      m1.cost=cost;
    } else if (cost < m2.cost) {
      m2.color=color;
      m2.cost=cost;
    }
  };

  Min m1, m2;
  for (int i=0; i<K; i++) { // first house
    const int cost = input[0][i];
    set_min(cost, i, m1, m2);
  }

  for (int house=1; house<N; house++) { // other houses (if any)
    Min c1, c2;
    for (int color=0; color<K; color++) {
      int prev_cost = color==m1.color? m2.cost : m1.cost;
      int cost = input[house][color] + prev_cost;
      set_min(cost, color, c1, c2);
    }
    m1=c1;
    m2=c2;
  }

  return m1.cost;
}



#include "test/019.h"
int main() { run_tests(); return 0; }