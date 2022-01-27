#include <string>
#include <climits>
using namespace std;

int _distanceBF(string a, string b, int i, int j){
  if (i == 0 && j == 0) return 0;
  else if (i==0) return j; // consumed a completely. do b inserts
  else if (j==0) return i; // consumed b completely. do a deletions.

  int cost_del = 1 + _distanceBF(a, b, i-1, j);
  int cost_add = 1 + _distanceBF(a, b, i, j-1); // like removing from b

  int cost_replace = (a[i-1]==b[j-1]?0:1) + _distanceBF(a, b, i-1, j-1);

  int mn = min(cost_del, cost_add);
  return min(mn, cost_replace);
}

int string_distanceBF(string a, string b) { return _distanceBF(a, b, a.size(), b.size()); }


#include <vector>
int _distanceMMZ(string a, string b, int i, int j, vector<vector<int>>& mmz) {
  if (i==0) return j; // match what's left: perform b inserts
  if (j==0) return i; // delete what's left: a deletions

  if (mmz[i][j] != -1) return mmz[i][j];

  int cost_del = 1+_distanceMMZ(a, b, i-1, j, mmz);
  int cost_add = 1+_distanceMMZ(a, b, i, j-1, mmz);
  int cost_replace =
      (a[i-1]==b[j-1]? 0:1) + _distanceMMZ(a, b, i-1, j-1, mmz);

  int mn = min(cost_del, cost_add);
  mn = min(mn, cost_replace);
  mmz[i][j] = mn;
  return mn;
}

int string_distanceMMZ(string a, string b ) {
  vector<vector<int>> mmz(a.size()+1, vector<int>(b.size()+1, -1));
  return _distanceMMZ(a, b, a.size(), b.size(), mmz);
}


int string_distanceBU(string a, string b) {
  vector<vector<int>> cost(a.size()+1, vector<int>(b.size()+1, 0));

  // b consumed. for i chars we need i deletions
  for (int i=0; i<=a.size(); i++) cost[i][0]=i;
  // a consumed. for j chars we need j insertions
  for (int j=0; j<=b.size(); j++) cost[0][j]=j;


  for (int i=1; i<=a.size(); i++) {
    for (int j=1; j<=b.size(); j++) {
      int cost_del = 1+cost[i-1][j];
      int cost_add = 1+cost[i][j-1];
      int cost_replace = (a[i-1]==b[j-1]?0:1) + cost[i-1][j-1];

      cost[i][j]=min(cost_add, cost_del);
      cost[i][j]=min(cost[i][j], cost_replace);
    }
  }

  return cost[a.size()][b.size()];
}



int string_distanceOPT_SlightlyDifferent() {
  vector<int> prev(to.size()+1);
  vector<int> cur(to.size()+1);
  for (int a=0; a<=from.size(); a++) { // Set
    for (int b=0; b<=to.size(); b++) { // Be
      if (a==0) cur[b]=b;
      else if (b==0) cur[b]=a;
      else {
        int del = 1 + prev[b]; // up
        int ins = 1 + cur[b-1]; // left
        int replCost = from[a-1]==to[b-1] ? 0:1;
        int repl = replCost + prev[b-1]; // diagonal
        cur[b]=min(del, ins);
        cur[b]=min(cur[b], repl);
      }
    }
    for (auto c: cur) cout << c << " "; cout << endl;
    swap(cur, prev);
  }
  return prev[to.size()]; // due to the last swap..
}


int string_distanceOPT(string a, string b) {
  // two rows
  vector<int> cost_prev(b.size()+1);
  vector<int> cost_cur(b.size()+1);

  // b consumed. for i chars we need i deletions
  for (int j=0; j<=b.size(); j++) cost_cur[j]=j;

  // a consumed. for j chars we need j insertions
  // do this on the fly in the loops below
  // for (int j=0; j<=b.size(); j++) cost[0][j]=j;

  for (int i=1; i<=a.size(); i++) {

    // swap rows and fix when i=0
    swap(cost_prev, cost_cur);
    cost_cur[0]=i;

    for (int j=1; j<=b.size(); j++) {
      int cost_del = 1+cost_prev[j]; // prev row
      int cost_add = 1+cost_cur[j-1]; // prev col
      // prev col+row
      int cost_replace = (a[i-1]==b[j-1]?0:1) + cost_prev[j-1];

      cost_cur[j]=min(cost_add, cost_del);
      cost_cur[j]=min(cost_cur[j], cost_replace);
    }
  }

  // because they swapped.
  return cost_cur[b.size()];
}


#include "test/031.h"
int main() {
  // run_tests("BF", string_distanceBF);
  // run_tests("MMZ", string_distanceMMZ);
  // run_tests("BU", string_distanceBU);
  run_tests("OPT", string_distanceOPT);
  return 0;
}