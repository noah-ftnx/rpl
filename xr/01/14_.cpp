#include <vector>
using namespace std;

/*

res {}; 2D

step 2:
interval=intervals[0]; // current interval
for: i 1 to N (DONT ++)

- if interval.end >= next start: merge.
  - go to next iteration..
else:
  - push interval in res
        - start new: interval=intervals[i];

// after loop:
add very last interval to res

*/

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  const int N = (int) intervals.size();
  if (intervals.empty()) return {};
  sort (intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) -> bool{
    return a[0]<b[0];
  });

  vector<vector<int>> res;

  auto interval=intervals[0]; // current interval
  for (int i=1; i<N; i++) {
    if (interval[1] >= intervals[i][0]) { // overlapping
      interval[1]=max(interval[1], intervals[i][1]); // TRICK: updating ending number
    } else if (interval[1] < intervals[i][0]) { // non overlapping
      // add it to result
      res.push_back(interval);
      interval=intervals[i];
    }
  }

  res.push_back(interval);

  return res;
}
}