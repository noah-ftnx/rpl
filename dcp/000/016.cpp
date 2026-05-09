
class Log {
 private:

 public:
  // IMPLEMENT: record
  void record(int order_id);

  // IMPLEMENT: get_last
  int get_last(int i);

};



#include "test/016.h"
int main() { run_tests(); return 0; }