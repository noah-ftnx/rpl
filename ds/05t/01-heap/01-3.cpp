#include <vector>
using namespace std;

// IMPLEMENT: heapsort
void heapsort(vector<int> &vec);

#include "test/01-3.h"
int main() {
  run_tests(heapsort, "heapsort");
  print_report();
  return 0;
}
