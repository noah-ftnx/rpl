
struct Coord {
  int x; int y;
};


// 3D vector: store initialized board and each steps
//            (for correctness verification)
void GOL(vector<Coord> live_cells, int steps,
         vector<vector<vector<bool>>>& result);



#include "test/039.h"
int main() { run_tests(); return 0; }