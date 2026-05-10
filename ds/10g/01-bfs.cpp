#include <list>
#include <vector>
#include <iostream>
using namespace std;

struct Edge {
  int id {};
  int weight {};
};

// IMPLEMENT: BFS
void BFS(const vector<list<Edge>>& G, int src);



#include "test/01.h"
int main () { run_tests(); return 0; }
