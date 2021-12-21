#include <vector>
using namespace std;

int bf(const vector<int>& vec, int i =0) {
  if (i >= vec.size()) return 0;
  return max(vec[i]+bf(vec, i+2), bf(vec, i+1));
}

int sum_naBF(const vector<int>& vec) {
  return bf(vec);
}

int td(vector<int>&mmz, const vector<int>& vec, int i =0) {
  if (i >=vec.size()) return 0;
  if (mmz[i]!=-1) return mmz[i];
  mmz[i]=max(vec[i]+td(mmz,vec,i+2), td(mmz,vec,i+1));
  return mmz[i];
}

int sum_naTD(const vector<int>& vec) {
  vector<int> mmz(vec.size(), -1);
  return td(mmz, vec);
}

int sum_naBU(const vector<int>& v) {
  vector<int> sol(v.size()+2, 0);
  for (int i=v.size()-1; i>=0; i--) {
    sol[i]=max(v[i]+sol[i+2], sol[i+1]);
  }
  return sol[0];
}

int sol(const vector<int>& v) {
  int s2,s1,s; s2=s1=s=0;
  for (int i=v.size()-1; i>=0; i--) {
    s = max(v[i]+s2, s1) ;
    s2=s1;
    s1=s;
  }

  return s;
}

#include "test/009.h"
int main() {
  run_tests("BF", sum_naBF);
  run_tests("TD", sum_naTD);
  run_tests("BU", sum_naBU);
  run_tests("sol", sol);
  return 0;
}