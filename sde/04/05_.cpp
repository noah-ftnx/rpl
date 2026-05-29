#include <vector>
#include <unordered_map>

using namespace std;

int subarraysXorBF(vector<int> &arr, int x) {
  const int N = (int) arr.size();
  int cnt=0;
  for (int i=0; i<N; i++) {
    int num=0;
    for (int j=i; j<N; j++) {
      num=num xor arr[j];
      if (num==x) cnt++;
    }
  }
  return cnt;
}


int subarraysXor(vector<int> &arr, int k) {
  const int N = (int) arr.size();
  int cnt=0;
  int xpr=0; // prefix xor
  unordered_map<int, int> mp;
  mp[0]=1;

  for (int i=0; i<N; i++) {
    xpr=xpr^arr[i];

    int y = xpr^k;
    if (mp.count(y)) cnt+=mp[y];
    mp[xpr]++;
  }
  return cnt;
}

#include "test/05.h"
int main() {
  run_tests(subarraysXorBF, "subarraysXorBF");
  run_tests(subarraysXor, "subarraysXor");
  print_report();
  return 0;
}
