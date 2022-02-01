#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

struct MinHeapEndTime {
  bool operator()(pair<int,int> a, pair<int,int> b) {
    return a.second > b.second;
  }
};

int min_rooms(vector<pair<int, int>> timetable) {
  sort(timetable.begin(), timetable.end(),
       [] (pair<int, int> a, pair<int, int> b) { return a.first < b.first; });

  priority_queue<pair<int,int>, vector<pair<int,int>>, MinHeapEndTime> pq;

  int mx = 0;
  for (auto p: timetable) {
    // remove all lectures that finish before next lecture start
    while (!pq.empty() && p.first >= pq.top().second) pq.pop();

    pq.push(p);
    mx = max(mx, (int)pq.size());
  }
  return mx;
}



#include "test/021.h"
int main() { run_tests(); return 0; }