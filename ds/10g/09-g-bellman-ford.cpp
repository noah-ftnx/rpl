#include <vector>
using namespace std;

struct Edge {
  int src;
  int dest;
  int weight;
};

struct Graph {
  vector<Edge> edges;

  Graph(int V, int E):

  vector<int> BellmanFord(int src);

};



#include "test/09-g-bellman-ford.h"
int main() { run_tests(); return 0; }