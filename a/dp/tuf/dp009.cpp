
int mazeObstaclesBF(int n, int m, vector<vector<int>> &mat);

int mazeObstaclesMMZ(int n, int m, vector<vector<int>> &mat);

int mazeObstaclesBU(int n, int m, vector<vector<int>> &mat);

int mazeObstaclesOPT(int n, int m, vector<vector<int>> &mat);



#include "test/dp009.h"
int main() {
  run_tests("BF", mazeObstaclesBF);
  // run_tests("MMZ", mazeObstaclesMMZ);
  // run_tests("BU", mazeObstaclesBU);
  // run_tests("OPT", mazeObstaclesOPT);

  print_errors();
  return 0;
}