
int unboundedKnapsackBF(int n, int w, vector<int> &profit, vector<int> &weight);

int unboundedKnapsackMMZ(int n, int w, vector<int> &profit, vector<int> &weight);

int unboundedKnapsackBU(int n, int w, vector<int> &profit, vector<int> &weight);

int unboundedKnapsackOPT(int n, int w, vector<int> &profit, vector<int> &weight);



#include "test/dp023.h"
int main() {
  run_tests("BF", unboundedKnapsackBF);
  // run_tests("MMZ", unboundedKnapsackMMZ);
  // run_tests("BU", unboundedKnapsackBU);
  // run_tests("OPT", unboundedKnapsackOPT);

  print_report();
  return 0;
}