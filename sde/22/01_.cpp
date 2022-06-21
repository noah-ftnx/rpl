#include <queue>
#include <vector>
using namespace std;

class KthLargest {
 private:
  const int k;
  priority_queue<int, vector<int>, greater<int>> pq;

  void insert(int el) {
    // if haven't filled k elements yet, or smaller than top
    if (pq.size() < k || el > pq.top()) {
      pq.push(el);
    }

    if (pq.size() > k) pq.pop();  // keep only k elements
  }

 public:

  KthLargest(int k, vector<int>& nums) : k{k} {
    for (int num: nums) insert(num);
  }

  int add(int val) {
    insert(val);
    return pq.top();
  }
};