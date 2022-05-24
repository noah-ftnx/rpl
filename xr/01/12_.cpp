#include <vector>

using namespace std;

vector<int> apOPT(vector<int> a) {
  const int N = (int) a.size();
  vector<int> res(N, 1); // TRICKY: last row is not inited in the first loop. so it'll be zero
  int prod=1;

  for (int i=N-2; i>=0; i--) {
    prod*=a[i+1];
    res[i]=prod;
  }

  prod=1;
  for (int i=1; i<N; i++) {
    prod*=a[i-1];
    res[i]*=prod;
  }

  return res;
}
