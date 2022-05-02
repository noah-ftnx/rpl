#include <climits>
#include <vector>
using namespace std;


int BF(int n, int k, vector<int> &heights) {
  if (n==0) return 0; // base case

  int mn_cost=INT_MAX;
  for (int i=1; i<=k; i++) {
    if (n-i>=0) {
      mn_cost=
          min(mn_cost,
              abs(heights[n]-heights[n-i]) + BF(n-i, k, heights));
    }
  }

  return mn_cost;
}

int frogJump2BF(int n, int k, vector<int> &heights) {
  n--;
  if (n<0 || k<=0 || n>=(int)heights.size()) return -1;
  else if (n==0) return 0;

  return BF(n, k, heights);
}



int MMZ(int n, int k, vector<int> &heights, vector<int> &mmz) {

  if (n==0) return 0; // base case
  else if (mmz[n]!=-1) return mmz[n];

  int mn_cost=INT_MAX;
  for (int i=1; i<=k; i++) {
    if (n-i>=0) {
      mn_cost=min(mn_cost,
         abs(heights[n]-heights[n-i]) + MMZ(n-i, k, heights, mmz));
    }
  }

  return mmz[n]=mn_cost;
}

int frogJump2MMZ(int n, int k, vector<int> &heights) {
  n--;
  if (n<0 || k<=0 || n>=(int)heights.size()) return -1;
  else if (n==0) return 0;

  vector<int> mmz(n+1, -1);
  return MMZ(n, k, heights, mmz);
}

int frogJump2BU(int n, int k, vector<int> &heights) {
  n--;
  if (n<0 || k<=0 || n>=(int) heights.size()) return -1;
  else if (n==0) return 0;

  vector<int> tab(n+1, 0);
  tab[0]=0;

  for (int j=1; j<=n; j++) {
    int mn_cost=INT_MAX;
    for (int i=1; i<=k; i++) {
      if (j-i>=0) {
        mn_cost=min(mn_cost,
                    abs(heights[j]-heights[j-i]) + tab[j-i]);
      }
    }
    tab[j]=mn_cost;
  }
  return tab[n];
}


#include <deque>
int frogJump2OPT(int n, int k, vector<int> &heights) {
  n--;
  if (n<0 || k<=0 || n>=(int) heights.size()) return -1;
  else if (n==0) return 0;

  deque<int> window(k, 0);
  window[k-1]=0;

  for (int j=1; j<=n; j++) {
    int mn_cost=INT_MAX;
    for (int i=1; i<=k; i++) {
      if (j-i>=0) {
        mn_cost=min(mn_cost,
                      abs(heights[j]-heights[j-i]) + window[k-i]);
      }
    }

    // slide the window
    window.pop_front();
    window.push_back(mn_cost);
  }
  return window[k-1];
}



#include "test/dp004.h"
int main() {
  run_tests("BF", frogJump2BF);
  run_tests("TD", frogJump2MMZ);
  run_tests("BU", frogJump2BU);
  run_tests("OPT", frogJump2OPT);

  print_errors();
  return 0;
}