#ifdef POWERSET_RECURSIVE

#include <vector>
using namespace std;

void dfs(const vector<int> &v, vector<vector<int>> &pset,
         vector<int> &cur, int idx) {
  const int V = (int) v.size();
  pset.push_back(cur);

  if (idx==V) return;

  for (int i=idx; i<V; i++) {
    cur.push_back(v[i]);
    dfs(v, pset, cur, i+1);
    cur.pop_back();
  }
}

vector<vector<int>> pwset(vector<int>v) {
  vector<vector<int>> pset; vector<int> cur;
  dfs(v, pset, cur, 0);
  return pset;
}

#endif


#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> pwset(vector<int>v) {
  const int BITS = (int) v.size();
  const int N = pow(2, BITS);
  vector<vector<int>> res;
  for (int i=0; i<N; i++) {
    vector<int> cur;
    // 2 1 0
    // 0 0 1: when 1st bit is set
    for (int b=0; b<BITS; b++) {
      bool bitSet = (i>>b)&1;
      if (bitSet) {
        // int idx = BITS-1-b;
        // NO NEED FOR REVERSE: 0th bit is on the right!
        cur.push_back(v[b]);
      }
    }
    res.push_back(cur);
  }
  return res;
}