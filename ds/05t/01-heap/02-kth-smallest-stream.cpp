#include "test/02-kth-smallest-stream-pre.h"

// Implement:
class KthSmallest {
 public:
  explicit KthSmallest(int k);

  optional<int> add(int val);
};

#include "test/02-kth-smallest-stream.h"
int main() { run_tests(); return 0; }
