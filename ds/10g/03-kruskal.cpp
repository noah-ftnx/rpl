
const int V=7;
const int E=9;

struct Edge {
  int from;
  int to;
  int w; // weight
};

vector<Edge> MST(vector<Edge> edges, int V);



#include "test/03.h"
int main() { run_tests(); return 0; }