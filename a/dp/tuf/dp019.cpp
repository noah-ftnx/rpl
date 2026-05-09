
// IMPLEMENT: knapsackBF
int knapsackBF(vector<int> weight, vector<int> value, int n, int maxWeight);

// IMPLEMENT: knapsackMMZ
int knapsackMMZ(vector<int> weight, vector<int> value, int n, int maxWeight);

// IMPLEMENT: knapsackBU
int knapsackBU(vector<int> weight, vector<int> value, int n, int maxWeight);

// IMPLEMENT: knapsackOPT
int knapsackOPT(vector<int> weight, vector<int> value, int n, int maxWeight);



#include "test/dp019.h"
int main() {
  run_tests("BF", knapsackBF);
  // run_tests("MMZ", knapsackMMZ);
  // run_tests("BU", knapsackBU);
  // run_tests("OPT", knapsackOPT);

  print_report();
  return 0;
}