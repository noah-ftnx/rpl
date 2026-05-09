#include <vector>
using namespace std;

// IMPLEMENT: paths_num
int paths_num(int N, int M);

// IMPLEMENT: paths_numOPT
int paths_numOPT(int N, int M);



#include "test/062.h"
int main() {
  run_tests("BU", paths_num);
  run_tests("OPT", paths_numOPT);
  return 0;
}