#include <vector>
#include <algorithm>
using namespace std;

vector<int> kMaxSumCombinationBF(vector<int> &a, vector<int> &b, int n, int k){

  vector<int> combinations;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      combinations.push_back(a[i]+b[j]);
    }
  }

  sort(combinations.begin(), combinations.end(), greater<int>());
  combinations.resize(k);

  return combinations;
}


#include <queue>
#include <set>
#include <unordered_set>
using namespace std;

struct Tuple { int sum, i, j; };

struct PairHash {
  size_t operator()(pair<int, int> p) const {
    return p.first ^ p.second;
  }
};

struct TupleCmp {
  bool operator()(Tuple a, Tuple b) {
    // Create MaxHeap on sum
    return a.sum < b.sum; // if smaller: percolate down
  }
};

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end(), greater<int>());


  priority_queue<Tuple, vector<Tuple>, TupleCmp> pq;
  unordered_set<pair<int, int>, PairHash> unq; // unique coordinates
  pq.push({a[0]+b[0], 0, 0});

  vector<int> res;
  while (res.size() <k) {
    auto t = pq.top(); pq.pop();
    res.push_back(t.sum);

    if(t.i+1 <n && unq.insert({t.i+1, t.j}).second) {
      pq.push({a[t.i+1]+b[t.j], t.i+1, t.j});
    }

    if (t.j+1 < n && unq.insert({t.i, t.j+1}).second) {
      pq.push({a[t.i]+b[t.j+1], t.i, t.j+1});
    }
  }
  return res;
}