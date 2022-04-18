#include <list>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Edge {
  int id {};
  int weight {};
};

void BFS(const vector<list<Edge>>& G, int src);



#include "test/01.h"
int main () { run_tests(); return 0; }