

#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

#define INF INT_MAX

#include "test/11.h"

int reduceMatrix(vector<vector<int>> &m) {
  // REDUCTION: EACH COLUMN:
  int reduction=0;
  const int N = m.size();
  for (int i=0; i<N; i++) {
    int mn = m[i][0];
    for (int j=1; j<N; j++) mn=min(mn, m[i][j]);

    // cout << "col min: " << pretty_num(mn) << endl;

    // apply reduction
    // if not infinity (each val is infinity)
    // or not zero (already reducted) then apply reduction
    if (mn>0 && mn != INF) {
      reduction+=mn;
      for (int j=0; j<N; j++)
        if (m[i][j] != INF) m[i][j]-=mn;
    }
  } // end of col reduction

  // ROW REDUCTION
  for (int j=0; j<N; j++) {
    int mn = m[0][j];
    for (int i=1; i<N; i++) mn=min(mn, m[i][j]);

    if (mn>0 && mn != INF) {
      reduction+=mn;
      for (int i=0; i<N; i++)
        if (m[i][j] != INF) m[i][j]-=mn;
    }
  } // end of row reduction

  return reduction;
}

struct Item {
  int idx;
  int level;
  int cost;
  vector<vector<int>> matrix; // reducted matrix
  Item(int idx, int level, int cost, vector<vector<int>> matrix) :
    idx{idx}, level{level}, cost{cost}, matrix{matrix}
  {
  }
};
struct ItemCmp {
  bool operator()(Item &a, Item &b) {
    return a.cost > b.cost; // bigger costs percolate down
  }
};


vector<vector<int>> prepareChildMatrix(const vector<vector<int>> &m, int par, int nei) {
  vector<vector<int>> cpy=m;
  const int N = m.size();
  for (int j=0; j<N; j++) cpy[par][j]=INF;
  for (int i=0; i<N; i++) cpy[i][nei]=INF;

  cpy[nei][par]=INF; // cannot go back
  return cpy;
}

// TSP w/ Branch and Bound
int tsp(vector<vector<int>> orig) {
  if (orig.empty()) return 0;

  const int N = orig.size();
  cout << "SIZE IS: " << N << endl;

  cout << "ORIG MATRIX:\n";
  cout << to_string_pretty(orig, true);
  cout <<"\n\n";

  auto cpy= orig; // copy
  int reduction = reduceMatrix(cpy);
  auto root = Item(0, 1, reduction, cpy);

  cout << "initial reduction done: " << reduction << endl;

  cout << "INITIAL RED VEC:\n";
  cout << to_string_pretty(cpy, true);
  cout << "\n\n";

  int UPPER_BOUND=INF; // this contain the final result..
  priority_queue<Item, vector<Item>, ItemCmp> pq;
  pq.push(root);
  while (!pq.empty()) {
   auto tp = pq.top(); pq.pop();
    cout << "\n\n# POP: " << tp.idx  << " lvl: " << tp.level << " cost: " << tp.cost << endl;
    for (int nei=0; nei<N; nei++) {  // explore valid neighbors
      int weight = tp.matrix[tp.idx][nei]; // weight of edge
      // auto nei: tp.matrix[tp.idx]
     if (weight == INF) continue;  // ignore visited paths

     auto cpy = prepareChildMatrix(tp.matrix, tp.idx, nei);
     int reduction = reduceMatrix(cpy);

     cout << "FROM: " << tp.idx << " TO: " << nei << " Weight: " << weight << endl;
     cout << to_string_pretty(cpy, true);
     cout << endl << endl;

     // make INF: row tp.idx and col nei
     int cost = tp.cost + reduction + tp.matrix[tp.idx][nei];

     cout << "cost: " << cost << endl;

     if (cost > UPPER_BOUND) continue; // ELIMINATED! (pruned by bound)

      cout << "not eliminated. pushing\n";

     auto item = Item({nei, tp.level+1, cost, cpy});
     pq.push(item);

     if (item.level==N) {
       UPPER_BOUND=min(UPPER_BOUND, cost);
       cout << "SMALLER UB: " << UPPER_BOUND << endl;
     }
   }
  }

  return UPPER_BOUND;
}

#include "test/11.h"
int main() { run_tests(tsp); return 0; }