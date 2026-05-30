#include <vector>
using namespace std;

class Solution {
 public:
  // IMPLEMENT: shortest paths from source
  vector<int> dijkstra(int V, vector<vector<int>> adj[], int S);
};

#include "test/02.h"
int main() { run_tests(); return 0; }
