#include <vector>
using namespace std;

int BF(int n, const vector<int> &heights) {
  if (n==0) return 0;  // base case

  int left = abs(heights[n]-heights[n-1])+BF(n-1, heights);
  int right = INT_MAX; // invalid step (assuming out of bounds)
  if (n-2 >=0) {
    right=abs(heights[n]-heights[n-2])+BF(n-2, heights);
  }

  return min(left, right);
}

int frogJumpBF(int n, vector<int> &heights)
{
  n--; // zero-based indexing
  if (n >= heights.size() || heights.empty()) return -1;
  else if (n==0) return 0;

  return BF(n, heights);
}



int MMZ(int n, const vector<int> &heights, vector<int> &mmz) {
  if (n==0) return 0;  // base case
  else if (mmz[n]!=-1) return mmz[n];

  int left = abs(heights[n]-heights[n-1])+MMZ(n-1, heights, mmz);
  int right = INT_MAX; // invalid step (assuming out of bounds)
  if (n-2 >=0) {
    right=abs(heights[n]-heights[n-2])+MMZ(n-2, heights, mmz);
  }

  return mmz[n]=min(left, right);
}

int frogJumpMMZ(int n, vector<int> &heights)
{
  n--; // zero-based indexing
  if (n >= heights.size() || heights.empty()) return -1;
  else if (n==0) return 0;
  vector<int> mmz(n+1, -1);
  return MMZ(n, heights, mmz);
}


int frogJumpBU(int n, vector<int> &heights)
{
  n--; // zero-based indexing
  if (n >= heights.size() || heights.empty()) return -1;
  else if (n==0) return 0;

  vector<int> tab(n+1, 0);
  tab[0]=0;
  for (int i=1; i<=n; i++) {
    int left = abs(heights[i]-heights[i-1])+tab[i-1];
    int right = INT_MAX; // invalid step (assuming out of bounds)
    if (i-2 >=0) {
      right=abs(heights[i]-heights[i-2])+tab[i-2];
    }
    tab[i]=min(left, right);
  }

  return tab[n];
}



int frogJumpOPT(int n, vector<int> &heights)
{
  n--; // zero-based indexing
  if (n >= heights.size() || heights.empty()) return -1;
  else if (n==0) return 0;

  vector<int> tab(n+1, 0);
  int p2, p1=0, cur;
  for (int i=1; i<=n; i++) {
    int left = abs(heights[i]-heights[i-1])+p1;
    int right = INT_MAX; // invalid step (assuming out of bounds)
    if (i-2 >=0) {
      right=abs(heights[i]-heights[i-2])+p2;
    }
    cur=min(left, right);
    p2=p1;
    p1=cur;
  }

  return cur;
}



#include "test/dp003.h"
int main() {
  run_tests("BF", frogJumpBF);
  run_tests("TD", frogJumpMMZ);
  run_tests("BU", frogJumpBU);
  run_tests("OPT", frogJumpOPT);

  print_errors();
  return 0;
}