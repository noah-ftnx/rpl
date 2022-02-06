#ifndef RPL_DCP_051_TEST_051_H_
#define RPL_DCP_051_TEST_051_H_

#include <iostream>
#include <iomanip>

bool _wrong {};

void test(vector<int> deck) {
  cout << "shuffled deck: ";

  shuffle(deck);
  for (auto i: deck) cout << " " << i;
  cout << endl;
}

void run_tests() {
  const int N = 5;
  for (int i=0; i<N; i++) test({1, 2, 3, 4, 5});
}

#endif  // RPL_DCP_051_TEST_051_H_
