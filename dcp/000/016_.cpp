#include <climits>
using namespace std;

class Log {
 private:
  const int N;
  int *array;
  int last_idx=-1;

 public:
  Log(int N) : N{N} {
    array = new int[N];
  }

  void record(int order_id) {
    last_idx++;
    if (last_idx == N) last_idx=0; // start over or init
    
    array[last_idx]=order_id;
  }

  int get_last(int i) {
    if (last_idx<0 || i<=0) return INT_MIN;
    int idx = last_idx-i+1;
    if (idx < 0) idx+=N;

    return array[idx];
  }
};



#include "test/016.h"
int main() { run_tests(); return 0; }