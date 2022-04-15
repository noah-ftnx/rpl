#include <climits>
#include <vector>
using namespace std;

// #define BRUTE_FORCE

#ifndef BRUTE_FORCE
struct ColCost {
  int color; int cost;
};

void min2(vector<int> row, ColCost& c1, ColCost& c2) {
  c1 = {-1, INT_MAX};
  c2 = {-1, INT_MAX};
  for (int i=0; i< (int) row.size(); i++) {
    if (row[i] < c1.cost) {
      c2=c1;
      c1.color=i;
      c1.cost=row[i];
    } else if (row[i] < c2.cost) {
      c2.color=i;
      c2.cost=row[i];
    }
  }
}

int paint_houses(vector<vector<int>> input) {
  if (input.empty()) return -1; // no houses

  const int N = (int) input.size();
  const int K = (int) input[0].size();
  if (K == 0) return -1; // no colors
  else if (N>1 && K==1) return -1;  // many houses, not enough colors

  ColCost c1,c2;
  vector<int> row = input[0];
  min2(row, c1, c2);

  for (int house=1; house<N; house++) {
    for (int color=0; color<K; color++) {
      row[color]= input[house][color]+
                   (color==c1.color? c2.cost:c1.cost);
    }
    min2(row, c1, c2);
  }

  return c1.cost;
}
#endif


//////////////////////////
////////////// BRUTE FORCE
//////////////////////////

#ifdef BRUTE_FORCE
int BF(const vector<vector<int>>& input,
       int cur_cost, int house, int prev_color) {
  const int N = (int) input.size();
  const int K = (int) input[0].size();

  if (house==N) return cur_cost;

  int mn_cost = INT_MAX;
  for (int color=0; color<K; color++) {
    if (color==prev_color) continue;

    mn_cost=min(mn_cost,
                  BF(input, cur_cost+input[house][color], house+1, color));
  }

  return mn_cost;
}

int paint_houses(vector<vector<int>> input) {
  if (input.empty()) return -1;

  const int N = (int) input.size();
  const int K = (int) input[0].size();
  if (K == 0) return -1;
  else if (N>1 && K==1) return -1;

  return BF(input, 0, 0, -1);
}

#endif



#include "test/019.h"
int main() { run_tests(); return 0; }