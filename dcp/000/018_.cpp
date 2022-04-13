// k:3
// [10, 5, 2, 7, 8, 7]

//      10, 5, 2, 7, 8, 7
//
//  10: 10, 5, 2
//  7:      5, 2, 7,
//  8:         2, 7, 8
//  8:            7, 8, 7

// len: 6
// results: 4

#include <vector>
#include <deque>
using namespace std;

vector<int> largest_subarray(vector<int> arr, int k) {
  const int N = (int) arr.size();
  /* sliding window of max k indices.
   we keep indices (and not values):
   - we can still access the values from arr
   - we don't have to keep all k indices: we can remove:
      + expired indices (moved out of window)
      + unusable indices (smaller values before current ones)
   */
  deque<int> window;
  vector<int> result;
  for (int i=0; i<N; i++) {

    // remove expired indices (from left)
    while (!window.empty() && window.front()+k <= i) {
      window.pop_front();
    }

    // remove smaller numbers (from right)
    while(!window.empty() && arr[i] >= arr[window.back()]) {
      window.pop_back();
    }

    // add index (at right)
    window.push_back(i);

    if (i>=k-1) { // max is at left
      result.push_back(arr[window.front()]);
    }

  }

  return result;
}




#include "test/018.h"
int main() { run_tests(); return 0; }