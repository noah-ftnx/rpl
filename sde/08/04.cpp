struct Item {
  int value;
  int weight;
};

// IMPLEMENT: fractionalKnapsack
double fractionalKnapsack(int W, Item arr[], int n);

#include "test/04.h"
int main() { run_tests(); return 0; }
