#ifndef RPL_DCP_TEST_039_H_
#define RPL_DCP_TEST_039_H_

#include <iostream>
#include <iomanip>

void run_tests() {
  vector<Coord> live_cells {
      {0,0}, {0,1},
      {1,2},
      // {2,2},
      {3,2}, {3,0}, {3,3}};


  vector<vector<vector<bool>>> correct
      {
          //init step
          {{1, 1, 0, 0 },
           {0, 0, 1, 0 },
           {0, 0, 0, 0},
           {1, 0, 1, 1}},
          //step 1
          {{0, 1, 0, 0 },
           {0, 1, 0, 0 },
           {0, 1, 1, 1},
           {0, 0, 0, 0}},
          // step 2
          {{0, 0, 0, 0 },
           {1, 1, 0, 0 },
           {0, 1, 1, 0},
           {0, 0, 1, 0}}
      };

  vector<vector<vector<bool>>> result;
  GOL(live_cells, 2, result);

  cout << "\n\n" << (result!=correct? "WRONG RESULT.":"Correct.") << endl;
}


#endif  // RPL_DCP_TEST_039_H_