#include <vector>
#include <algorithm>
using namespace std;

int maximumActivities(vector<int> &start, vector<int> &finish) {
  struct Activity { int start, end; };

  vector<Activity> act;
  const int N = start.size();

  for (int i=0; i<N; i++) act.push_back({start[i], finish[i]});


  // sort base on ending time
  sort(act.begin(), act.end(), [](Activity a, Activity b){
    return a.end < b.end;
  });

  int cnt=0;
  int prevEnd=-1;
  for (int i=0; i<N; i++) {
    // can do activity if starts after prev end
    if (act[i].start >= prevEnd) {
      cnt++;
      prevEnd=act[i].end;
    }
  }
  return cnt;
}
