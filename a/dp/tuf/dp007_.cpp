#include <vector>
using namespace std;

int BF(vector<vector<int>> &points, int day, int prev_task) {
  // base case
  if (day==0) {
    int mx=-1;
    for (int i=0; i<3; i++) {
      if (i!=prev_task) mx=max(mx, points[day][i]);
    }
    return mx;
  }

  int mx=-1;
  for (int i=0; i<3; i++) {
    if (i!=prev_task) {
      mx=max(mx, points[day][i]+BF(points, day-1, i));
    }
  }

  return mx;
}

int ninjaTrainingBF(vector<vector<int>> &points)
{
  if (points.empty()) return 0;
  const int N = (int) points.size();
  return BF(points, N-1, 3);
}



int MMZ(vector<vector<int>> &points, int day, int prev_task,
        vector<vector<int>> &mmz) {
  if (day==0) {  // base case
    int mx=-1;
    for (int i=0; i<3; i++) {
      if (i!=prev_task) mx=max(mx, points[0][i]);
    }
    return mx;
  } else if (mmz[day][prev_task]!=-1) return mmz[day][prev_task];

  int mx=-1;
  for (int i=0; i<3; i++) {
    if (i!=prev_task) {
      mx=max(mx, points[day][i]+MMZ(points, day-1, i, mmz));
    }
  }
  return mmz[day][prev_task]=mx;
}

int ninjaTrainingMMZ(vector<vector<int>> &points) {
  if (points.empty()) return 0;
  const int N = (int) points.size();
  vector<vector<int>> mmz(N, vector<int>(4, -1));
  return MMZ(points, N-1, 3, mmz);

}



int ninjaTrainingBU(vector<vector<int>> &points) {
  if (points.empty()) return 0;
  const int N = (int) points.size();
  vector<vector<int>> tab(N, vector<int>(4, -1));

  // base case: day 0
  tab[0][0]= max(points[0][1], points[0][2]);  // 0 prev_task
  tab[0][1]= max(points[0][0], points[0][2]);  // 1
  tab[0][2]= max(points[0][0], points[0][1]);  // 2
  tab[0][3]= max(tab[0][2],    points[0][2]);  // no prev_task (single day in points)

  for (int day=1; day<N; day++) {
    for (int prev_task=0; prev_task<4; prev_task++) {
      int mx=-1;
      for (int task=0; task<3; task++) {
        if (task!=prev_task) {
                        mx=max(mx, points[day][task]+tab[day-1][task]);
        }
      }
      tab[day][prev_task]=mx;
    }
  }

  return tab[N-1][3];
}



int ninjaTrainingOPT(vector<vector<int>> &points) {
  if (points.empty()) return 0;
  const int N = (int) points.size();
  vector<int> cur(4, 0);
  vector<int> prev(4, 0);

  // base case: day 0
  cur[0]= max(points[0][1], points[0][2]);  // 0 prev_task
  cur[1]= max(points[0][0], points[0][2]);  // 1
  cur[2]= max(points[0][0], points[0][1]);  // 2
  cur[3]= max(cur[2],    points[0][2]);  // no prev_task (single day in points)

  for (int day=1; day<N; day++) {
    swap(cur, prev);
    for (int prev_task=0; prev_task<4; prev_task++) {
      int mx=-1;
      for (int task=0; task<3; task++) {
        if (task!=prev_task) {
          mx=max(mx, points[day][task]+prev[task]);
        }
      }
      cur[prev_task]=mx;
    }
  }

  return cur[3];
}





#include "test/dp007.h"
int main() {
  run_tests("BF", ninjaTrainingBF);
  run_tests("TD", ninjaTrainingMMZ);
  run_tests("BU", ninjaTrainingBU);
  run_tests("OPT", ninjaTrainingOPT);

  print_errors();
  return 0;
}