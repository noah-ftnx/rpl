#include <vector>
using namespace std;

// N = 2: 2
// 1. 1, 1
// 2. 2

// N = 3: 3
// st: 1 or 2
// 1. 1, 1, 1
// 2.    1, 2
// 3.    2, 1
int _bf(int i, vector<int> steps) {
  if (i<0)  return 0;
  if (i==0) return 1;

  int sum=0;
  for (int step: steps) {
    sum+=_bf(i-step, steps);
  }
  return sum;
}

int count_bf(int N, vector<int> steps) {
  if (N<=0) return 0;
  return _bf(N, steps);
}



int _td(int i, vector<int> steps, vector<int>& mmz) {
  if (i<0)  return 0;
  if (mmz[i] != 0) return mmz[i];

  int sum=0;
  for (int step: steps) {
    sum+=_td(i-step, steps, mmz);
  }
  mmz[i]=sum;
  return sum;
}

int count_td(int N, vector<int> steps) {
  if (N<=0) return 0;
  vector<int> mmz(N+1, 0);
  mmz[0]=1;
  _td(N, steps, mmz);
  return mmz[N];
}



int count_bu(int N, vector<int> steps) {
  if (N<=0) return 0;
  vector<int> res(N+1, 0);
  res[0]=1;
  for (int i=1; i<=N; i++) { // O(N*S)
    for (int step: steps) {
      if (i-step >=0) res[i]+=res[i-step];
    }
  }
  return res[N];
}



#include <deque>
int sol(int N, vector<int> steps) {
  if (N<=0) return 0;
  int max_step = 0;
  for (auto step: steps) max_step=max(max_step, step); // O(S)
  deque<int> temp(max_step-1, 0); // subsolutions in a sliding window
  temp.push_back(1);
  for (int i=1; i<=N; i++) { // O(N*S)
    int res = 0;
    for (int step: steps) {
      if (i-step >=0) res+=temp[max_step-step];
    }
    temp.pop_front();
    temp.push_back(res);
  }
  return temp.back();
}



#include "test/012.h"
int main() {
  test_function("BF", count_bf);
  test_function("TD", count_td);
  test_function("BU", count_bu);
  test_function("sol", sol);

  if (_wrong) { cout << "ERRORS FOUND.\n"; }

  return 0;
}

