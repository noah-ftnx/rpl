#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if (image.empty() || image[0].empty()) return image;
      
    const int N = (int) image.size();
    const int M = (int) image[0].size();
      
    auto inBounds = [&](pair<int, int> p) {
      int i = p.first, j=p.second;
      return (i>=0 && j>=0 && i<N && j<M);
    };
      
    // modifying an invalid position
    if (!inBounds({sr, sc})) return image;
      

    // will be modifying the original color
    const int origColor = image[sr][sc];
    // EDGE CASE: no further changes.
    // otherwise: we get infinite loop (in the queue below)
    if (origColor==color) return image;
      
    queue<pair<int, int>> q;
    q.push({sr, sc});
      
    // 4 directions offsets
    vector<int> X {-1,  1,  0,  0};
    vector<int> Y { 0,  0, -1, +1};
      
    while(!q.empty()) {
      auto p = q.front(); q.pop();
        
      // visit: color it
      image[p.first][p.second]=color;
        
      // push same color neighbors in 4 directions:
      for (int i=0; i<4; i++) {
        int x=X[i];
        int y=Y[i];
          
        pair<int, int> pos {p.first+x, p.second+y};
        // check bounds first. when in bounds and had same color, enqueue
        if (inBounds(pos) && image[pos.first][pos.second]==origColor) q.push(pos);
      }
    }
      
    return image;
  }
};