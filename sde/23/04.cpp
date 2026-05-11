#include <vector>
using namespace std;

class Solution {
public:
  // IMPLEMENT: isCycle using BFS
  bool isCycle(int V, vector<int> adj[]);
};

#include "test/04.h"
int main() { run_tests(); return 0; }
