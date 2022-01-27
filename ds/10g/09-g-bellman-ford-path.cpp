#include <vector>
#include <deque>
using namespace std;

struct Edge {
  int src;
  int dest;
  int weight;
};

struct Graph {

  const int V, E;
  vector<Edge> edges;

  Graph(int V, int E);

  deque<int> BellmanFord(int src, int tgt);

};



#include "test/09-g-bellman-ford-path.h"
int main() { run_tests(); return 0; }