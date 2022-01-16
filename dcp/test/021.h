#ifndef RPL_DCP_TEST_021_H_
#define RPL_DCP_TEST_021_H_

#include <iostream>

void test(vector<pair<int, int>> timetable, int correct) {
  int result = min_rooms(timetable);
  cout << "min rooms: " << result << (result!=correct? " (WRONG)": "") << endl;
}

void run_tests() {
  test({{30, 75}, {0, 50}, {60, 150}}, 2);
  test({{5, 7}, {0, 9}, {5, 9}}, 3);

  test({{0,1}, {0,2}, {0,3},  // 3 in this window
        {4,5}, {5,6}, {6,7}, // nothing overlaps
        {100,108}, {101,110}, {103,107}, {105,108}, // 4 overlaps
        {200,210}
       }, 4);

}

#endif  // RPL_DCP_TEST_021_H_