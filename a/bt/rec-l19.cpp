
#include <vector>
#include <string>
using namespace std;

// Given an N x N maze.
// 1 = open cell, 0 = blocked cell.
// Start: (0, 0). Destination: (N-1, N-1).
// Return all valid path strings in lexicographic order.
// A path cannot visit the same cell more than once.
// IMPLEMENT: findPath
vector<string> findPath(vector<vector<int>> &m);



#include "test/rec-l19.h"
int main() { run_tests(); return 0; }
