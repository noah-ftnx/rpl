#include <vector>
#include <string>
using namespace std;

string kth_permutation(int N, int K) {
  if (K<=0 || N<=0) return "<NAN>";

  vector<int> nums(N);
  int F=1;
  for (int i=0; i<N; i++) {
    nums[i]=i+1;
    F*=(i+1); // 1*2*3*4 .. 24
  }

  if (K>F) return "<NAN>";

  K--; // zero-based index...
  int n=N;

  string res;
  while (true) {

    if (n==1) {
      res+=to_string(nums[0]);
      break;
    }

    F/=n; // (n-1)!
    int pickIdx = K/F;
    res+=to_string(nums[pickIdx]);
    nums.erase(nums.begin() +pickIdx);
    K=K%F;
    n--;
  }

  return res;
}



#include "test/rec-l18.h"
int main() { run_tests(); return 0; }