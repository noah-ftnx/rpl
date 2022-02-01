#include <climits>

class Log {
 private:
  int *data {};
  const int N;
  int last_element {-1};
  bool filled {};

 public:
  Log(int N) : N{N} {
    data = new int[N];
  }

  // last: -1
  // 3:
  // 0, 1, 2
  // last: 0
  void record(int order_id) {
    last_element++; // 1
    if (last_element == N) { // reset to 0. will override logs.
      filled=true;
      last_element = 0;
    }
    data[last_element] = order_id;
  }

  int get_last(int i) { // i can be <= N
    if (i <= 0 || i > N) return INT_MIN; // so no zero indexing
    if (last_element < 0) return INT_MIN; //empty array
    // return the last from the end..
    int idx = last_element-(i-1);
    if (idx < 0) {
      if (!filled) return INT_MIN;
      idx+=N;
    }

    return data[idx];
  }
};



#include "test/016.h"
int main() { run_tests(); return 0; }