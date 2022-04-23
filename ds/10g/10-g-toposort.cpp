#include <vector>
#include <list>
#include <deque>
using namespace std;

struct Graph {
  Graph(int V);

  void addEdge(int v, int w);

  vector<int> linearize();

};



#include "test/10.h"
int main() { run_tests(); return 0; }
