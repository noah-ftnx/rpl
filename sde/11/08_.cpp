#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int aggressiveCows(vector<int> &stalls, int k)
{
  const int N = (int) stalls.size();
  if (N<2 || k<2) return INT_MIN;

  sort(stalls.begin(), stalls.end());

  // found ranges
  int low=INT_MAX, high=stalls[N-1]-stalls[0];
  for (int i=1; i<N; i++) {
    low=min(low, stalls[i]-stalls[i-1]);
  }

  auto isValid = [&](int minDistance) -> bool {
    int cows=k;
    cows--; // placed 1st cow on 1st stall
    int distance=0;
    // try to fit cows
    for (int i=1; i<N; i++) {
      distance+=stalls[i]-stalls[i-1];
      if (distance >= minDistance) {
        // can fit the next cow
        cows--;
        distance=0; // reset
      }
    }

    return cows <=0; // fit at least k cows
  };

  while (low <= high) {
    int mid = (low+high)/2;

    if (isValid(mid)) {
      // can fit k cows using mid as the min distance
      // try to increase this (go left)
      low=mid+1;
    } else {
      // cannot fit k cows with mid as min dist
      // try to decrease it (go right)
      high=mid-1;
    }
  }

  return high;
}
