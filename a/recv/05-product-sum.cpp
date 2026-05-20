#include <any>
#include <vector>
using namespace std;

// Given a nested array of integers.
// Every nested array has depth+1.
// Return the product sum.
// IMPLEMENT: productSum
int productSum(vector<any> array, int depth = 1);

#include "test/05-product-sum.h"
int main() { run_tests(); return 0; }
