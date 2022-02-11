#include <string> // for implemented methods

class LFU {

  int size();  // provide this also

  string to_string(); // GIVEN

  void set(int key, int value);
  int get(int key);

};



#include "test/067.h"
int main() { run_tests(); return 0; }