#include "test/02-kth-smallest-stream-pre.h"

class KthSmallest {
 public:
  // IMPLEMENT: KthSmallest
  explicit KthSmallest(int k);

  // IMPLEMENT: add
  optional<int> add(int val);
};

#include "test/02-kth-smallest-stream.h"
int main() { run_tests(); return 0; }
