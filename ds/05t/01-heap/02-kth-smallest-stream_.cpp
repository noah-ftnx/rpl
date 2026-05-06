#include "test/02-kth-smallest-stream-pre.h"

#include <queue>

class KthSmallest {
 private:
  int k {};
  priority_queue<int> pq; // max heap

 public:
  explicit KthSmallest(int k) : k{k} {}

  optional<int> add(int val) {
    if (k <= 0) return {};

    pq.push(val);

    // max heap keeps the largest value on top.
    // if size > k: remove the largest, so only k smallest remain.
    if ((int) pq.size() > k) pq.pop();

    if ((int) pq.size() < k) return {};
    return pq.top();
  }
};

#include "test/02-kth-smallest-stream.h"
int main() { run_tests(); return 0; }
