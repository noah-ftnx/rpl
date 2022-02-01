#ifndef RPL_DCP_TEST_045_H_
#define RPL_DCP_TEST_045_H_

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <unordered_map>

using namespace std;

void run_tests() {
  int M=20;
  unordered_map<int, int> mp;
  while (M--) {
    int num=rand7();
    usleep(300 * 1e3 + (rand()%100+10));
    if (mp.contains(num)) mp[num]=mp[num]+1;
    else mp[num]=1;
    cout << num << " " << flush;
  }
  cout << endl;

  cout << "\nDistribution:\n";
  for (auto p: mp) {
    cout << p.first << ": " << p.second << endl;
  }
}

#endif  // RPL_DCP_TEST_045_H_
