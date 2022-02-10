#ifndef RPL_DCP_051_TEST_064_H_
#define RPL_DCP_051_TEST_064_H_

#include "base.h"
#include <chrono>
using namespace std::chrono;

void experiment() {
  cout << __func__ << endl;
  cout << "Normal Tour: 5: " << &flush;
  auto start = high_resolution_clock::now();
  int result = knights_tour(5);
  auto stop = high_resolution_clock::now();
  cout << ": " << result << " time: " <<  duration_cast<seconds>(stop-start).count() << endl;

  _apply_heuristic=true;
  cout << "Heuristic Tour: 5: " << &flush;
  start = high_resolution_clock::now();
  result = knights_tour(5);
  stop = high_resolution_clock::now();
  cout << ": " << result << " time: " <<  duration_cast<seconds>(stop-start).count() << endl;
}

void test(int N, int correct) {
  int result = knights_tour(N);
  bool wrong = result!=correct;
  _wrong|=wrong;
  cout << N << ": tours: " << setw(4) << ": " << result
       << (wrong? " (WRONG)": "") << endl;
}

void run_tests() {

  test(1, 1);
  test(2, 0);
  test(3, 0);
  test(4, 0);
  test(5, 1728);
  // test(6, 6637920);

  // experiment();
}


#endif  // RPL_DCP_051_TEST_064_H_
