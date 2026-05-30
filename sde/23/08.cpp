#include <vector>
using namespace std;

class Solution {
 public:
  // IMPLEMENT: topological sort
  vector<int> topoSort(int V, vector<int> adj[]);
};

#include "test/08.h"
int main() { run_tests(); return 0; }
