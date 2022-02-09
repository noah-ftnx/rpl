#include <vector>
using namespace std;

uint64_t count_bf(int n) {
  if (n <=1) return 0;
  if (n==2) return 1;
  return (n-1) * (count_bf(n-1) + count_bf(n-2));
}

uint64_t _count_td(vector<int>& mmz, int n) {
  if(n<=1) return 0;
  if (n==2) return 1;
  if (mmz[n] != -1) return mmz[n];

  mmz[n] = (n-1) * (_count_td(mmz, n-1) + _count_td(mmz, n-2));
  return mmz[n];
}

uint64_t count_td(int n) {
  vector<int> mmz(n+1, -1);
  return _count_td(mmz, n);
}

uint64_t count_bu(int n) {
  if (n <=1) return 0;
  vector<int> v(n+1, 0);
  v[2]=1;

  for(int i=3; i<=n; i++) {
    v[i] = (i-1) * (v[i-1] + v[i-2]);
  }

  return v[n];
}

uint64_t sol(int n) {
  if (n<=1) return 0;
  if (n==2) return 1;
  int m2=0; // n==1
  int m1=1; // n==2
  int r;
  for (int i=3; i<=n; i++) {
    r = (i-1) * (m1 + m2);
    m2=m1;
    m1=r;
  }
  return r;
}



#include "test/001.h"

int main() {
  run_tests("BF", count_bf);
  run_tests("TD", count_td);
  run_tests("BU", count_bu);
  run_tests("sol", sol);
  return 0;
}