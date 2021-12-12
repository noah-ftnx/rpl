#include "test/input-mst.h"

#include <iostream>
using namespace std;

void MST(vector<Edge> edges, int V);

int main () {
  cout << "MST: undirected graph:\n";
  vector<Edge> edges(input_mst());

  MST(edges, V);

  cout << endl;

  cout << "Correct output:\n"
       << "(1,6) 5\n"
       << "(3,4) 8\n"
       << "(2,7) 10\n"
       << "(2,3) 12\n"
       << "(4,5) 16\n"
       << "(5,6) 20\n";
}

void MST(vector<Edge> edges, int V) {

}