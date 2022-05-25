#include <vector>
using namespace std;


vector<vector<int>> merge(vector<vector<int>>& intervals) {
  sort(intervals.begin(), intervals.end(),
       [] (vector<int> &a, vector<int> &b) {
         return a[0] < b[0];
       });

  const int N = (int) intervals.size();
  if (N==0) return {};
  vector<int> interval=intervals[0];
  vector<vector<int>> res;
  for (int i=0; i<N; i++) {
    if (interval[1] >= intervals[i][0]) { // overlapping
      interval[1]=max(interval[1], intervals[i][1]);
    } else { // no overlap
      res.push_back(interval);
      interval=intervals[i];
    }
  }

  // push last interval
  res.push_back(interval);

  return res;
}



#include "test/02.h"
int main() {
  run_tests("Sol", merge);

  print_report();
  return 0;
}

