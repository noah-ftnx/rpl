#include <vector>
using namespace std;

int BF(int N) {
  if (N==0) return 0;
  else if (N==1) return 1;

  return BF(N-1) + BF(N-2);
}

int fiboBF(int N) {
  if (N<0) return -1;
  return BF(N);
}



int MMZ(int N, vector<int> &mmz) {
  if (N==1) return 1;
  else if (N==0) return 0;
  else if (mmz[N]!=-1) return mmz[N];

  return mmz[N]=MMZ(N-1, mmz)+MMZ(N-2, mmz);
}

int fiboMMZ(int N) {
  if (N<0) return -1;
  vector<int> mmz(N+1, -1);

  return MMZ(N, mmz);
}



int fiboBU(int N) {
  if (N<0) return -1;
  vector<int> tab(N+1, -1);
  tab[0]=0;
  tab[1]=1;

  for (int i=2; i<=N; i++) {
    tab[i]=tab[i-1]+tab[i-2];
  }
  return tab[N];
}



int fiboOPT(int N) {
  if (N<0) return -1;
  if (N<=1) return N;

  int p2=0;
  int p1=1;
  int res;
  for (int i=2; i<=N; i++) {
    res=p1+p2;
    p2=p1;
    p1=res;
  }

  return res;
}



#include "test/dp001.h"
int main() {
  run_tests("BF", fiboBF);
  run_tests("TD", fiboMMZ);
  run_tests("BU", fiboBU);
  run_tests("OPT", fiboOPT);

  print_errors();
  return 0;
}