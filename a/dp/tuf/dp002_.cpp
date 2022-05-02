#include <vector>
using namespace std;

int BF(int n) {
  if (n<=0) return (n==0);  // base case

  int l = BF(n-1);
  int r = BF(n-2);

  return l+r;
}

int countBF(long long nStairs) {
  if (nStairs<=0) return 0;
  return BF(nStairs);
}



int MMZ(int n, vector<int>& mmz) {
  if (n<=0) return (n==0);  // base case
  else if (mmz[n]!=-1) return mmz[n];

  int l = MMZ(n-1, mmz);
  int r = MMZ(n-2, mmz);

  return mmz[n]=l+r;
}

int countMMZ(long long nStairs) {
  if (nStairs<=0) return 0;
  vector<int> mmz(nStairs+1, -1);
  return MMZ(nStairs, mmz);
}



int countBU(long long nStairs) {
  if (nStairs<=0) return 0;
  vector<int> tab(nStairs+1, 0);

  tab[0]=1;
  tab[1]=1;

  for (int i=2; i<=nStairs; i++) {
    tab[i]=tab[i-1]+tab[i-2];
  }

  return tab[nStairs];
}



int countOPT(long long nStairs) {
  if (nStairs<=0) return 0;

  int p2=1;
  int p1=1;
  int res=1;

  for (int i=2; i<=nStairs; i++) {
    res=p1+p2;
    p2=p1;
    p1=res;
  }

  return res;
}


#include "test/dp002.h"
int main() {
  run_tests("BF", countBF);
  run_tests("TD", countMMZ);
  run_tests("BU", countBU);
  run_tests("OPT", countOPT);

  print_errors();
  return 0;
}