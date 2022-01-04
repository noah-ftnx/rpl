
class Log {
 private:

 public:
  void record(int order_id);

  int get_last(int i);

};



#include "test/016.h"
int main() { run_tests(); return 0; }