#include <string> // for implemented methods

class LFU {

  // IMPLEMENT: size
  int size();  // provide this also

  string to_string(); // GIVEN

  // IMPLEMENT: set
  void set(int key, int value);
  // IMPLEMENT: get
  int get(int key);

};



#include "test/067.h"
int main() { run_tests(); return 0; }