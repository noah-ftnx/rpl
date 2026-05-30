#include <vector>
using namespace std;

// IMPLEMENT: matrix median
int getMedian(vector<vector<int>> &matrix);

#include "test/02.h"
int main() { run_tests("Matrix Median", getMedian); return 0; }
