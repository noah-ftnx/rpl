#include <queue>
#include <vector>
#include <utility>
using namespace std;

class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    /*
      put in queue: all rotten oranges
      count healthy oranges

    // IF 3 good oranges not connected with rotten ones?
    // TODO counter for this one?

    minute=0
    while(queue not empty:)
      - SZ=get queue size
      - minute++
      - do SZ pops:
        - pop a rotten orange. healthy--
        - rot it's neighbors (if not rotten) & push them to queue

    if healty orange: ret -1 else ret minutes


    */

    if (grid.empty() || grid[0].empty()) return -1;
    const int N = (int) grid.size();
    const int M = (int) grid[0].size();

    // count fresh oranges and enqueue rotten ones
    queue<pair<int, int>> q;
    int freshCount=0;
    for (int i=0; i<N; i++) {
      for (int j=0; j<M; j++) {
        switch (grid[i][j]) {
          case 1: freshCount++; break;
          case 2: q.push(make_pair(i, j)); break;
        }
      }
    }

    auto rottenNeighbors = [&](int x, int y) {
      // offsets for 4 directions: UP, LEFT, DOWN, RIGHT
      vector<int> X {-1, 0,1,0};
      vector<int> Y { 0,-1,0,1};

      for (int c=0; c<(int) X.size(); c++) {
        int i = x+X[c];
        int j = y+Y[c];

        const bool inBounds = i>=0 && j>=0 && i<N && j<M;
        const bool isFresh = inBounds && grid[i][j]==1;

        if (inBounds && isFresh) {  // rot this orange
          freshCount--;
          grid[i][j]=2;
          q.push(make_pair(i, j));
        }
      }
    };

    int minute=0;
    while (!q.empty() && freshCount>0) {
      int pops=q.size(); // visit level by level (to figure out minutes)
      while(pops-- > 0) {
        auto rotten = q.front(); q.pop();
        // cout << "rotten: " << rotten.first << "," << rotten.second << endl;

        // rotten neighbors & enqueue them
        rottenNeighbors(rotten.first, rotten.second);
      }
      minute++;
    }
    return freshCount>0? -1 : minute;
  }
};