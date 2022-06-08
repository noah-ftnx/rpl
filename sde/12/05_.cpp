#include <queue>
#include <vector>
using namespace std;

struct ArrayElements { int arr, idx, val; };

struct ArrayElementsCmp {
  bool operator()(ArrayElements a, ArrayElements b) {
    // MinHeap
    return a.val > b.val; // bigger values perc down
  }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k) {
  priority_queue<ArrayElements, vector<ArrayElements>, ArrayElementsCmp> pq;

  // init queue
  for(int i=0; i<k; i++) {
    if (!kArrays.empty()) {
      pq.push({i, 0, kArrays[i][0]});
    }
  }

  vector<int> res;
  while (!pq.empty()) {
    auto el = pq.top(); pq.pop();
    res.push_back(el.val);

    // push back (if there are still elements)
    int sz = kArrays[el.arr].size();
    if (el.idx+1 < sz) {
      pq.push({el.arr, el.idx+1, kArrays[el.arr][el.idx+1]});
    }
  }
  return res;
}
