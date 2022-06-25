#include <vector>
#include <climits>
#include <iostream>
using namespace std;

#define INF INT_MAX

void solve(vector<vector<int>> matrix, vector<bool> &visited, int &visitedCnt,
           int &curCost, int &mnCost, const int startIdx, int idx) {
  const int V = (int) matrix.size();
  if (visitedCnt==V-1) { // on the last node
    // going from last vertex to the starting vertex
    int edgeCost = matrix[idx][startIdx];
    if (edgeCost != INF) {
      mnCost=min(mnCost, curCost+edgeCost);
    }
    return;
  }

  visited[idx]=true;
  visitedCnt++;
  for (int nei=0; nei<V; nei++) {
    if (nei==idx || visited[nei]) continue;
    int edgeCost = matrix[idx][nei];
    if (edgeCost != INF) { // there's a valid path
      curCost+= edgeCost;
      solve(matrix, visited, visitedCnt, curCost, mnCost, startIdx, nei);
      curCost-=edgeCost;
    }
  }
  visited[idx]=false;
  visitedCnt--;
}

int tsp(vector<vector<int>> matrix) {
  const int V = (int) matrix.size();
  if (V<=1) return 0;

  vector<bool> visited(V, false);
  int visitedCnt, curCost=0,mnCost=INF;
  solve(matrix, visited, visitedCnt, curCost, mnCost, 0, 0);
  return mnCost;
}



#include "test/11.h"
int main() { run_tests(tsp); return 0; }