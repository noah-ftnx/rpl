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

using namespace std;
vector<int> largest_subarray(vector<int> arr, int k) {

  // sliding window of max k indices.
  // we keep indices (and not values):
  // - we can still access the values from arr
  // - we don't have to keep all k indices:
  //    + unusable ones can be removed (smaller values before current ones)
  //    + we can remove the indices that move out of the window
  deque<int> dq;
  // fill deque
  for (int i=0; i<k; i++) {
    // remove unusable indices: ones that reference smaller values. those will never be chosen.
    while(!dq.empty() && arr[i] >= arr[dq.front()]) dq.pop_front();

    dq.push_back(i);
  }

  vector<int> result;
  for (int i=k; i<arr.size(); i++) {
    result.push_back(arr[dq.front()]);

    // remove indices that will move out of the sliding window
    while(!dq.empty() && dq.front() <= i-k) dq.pop_front();

    // remove unusable indices
    while(!dq.empty() && arr[i] >= arr[dq[0]]) dq.pop_front();
    dq.push_back(i);
  }
  // last result
  result.push_back(arr[dq.front()]);

  return result;
}



#include "test/018.h"
int main() { run_tests(); return 0; }