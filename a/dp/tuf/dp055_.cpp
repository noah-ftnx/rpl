#include <vector>
using namespace std;

int maximalAreaOfSubMatrixOfAll1BF(vector<vector<int>> &mat, int n, int m) {
  int mx=0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      // ignore zeros..
      if (mat[i][j]==0) continue;

      // try for to add longest rows, as many times as possible
      // case:
      // x x x
      // x x x
      int colWidth=0;
      for (int y=j; y<m && mat[i][y]; y++) { // go right
        colWidth++;
      }
      // find how many of these columns
      int rows=1; // found 1 right above
      for (int x=i+1; x<n; x++) {  // find the next columns
        bool colOK=true;
        for (int y=j; y<m; y++) {  // go right
          if (mat[x][y]==0) { colOK=false; break; }
        }
        if (colOK) rows++;
        else break;
      }
      int area=rows*colWidth;
      mx=max(mx, area);

      // try longest columns, as many time as possible
      // case:
      // x x
      // x x
      // x x
      int rowHeight=0;
      for (int x=i; x<n && mat[x][j]; x++) { // go below
        rowHeight++;
      }
      // find how many of these rows
      int cols=1; // found 1 right above
      for (int y=j+1; y<m; y++) { // find the next rows
        bool rowOK=true;
        for (int x=i; x<n; x++) {  // go below
          if (mat[x][y]==0)  { rowOK=false; break; }
        }
        if (rowOK) cols++;
        else break;
      }
      area=cols*rowHeight;
      mx=max(mx, area);
    }
  }
  return mx;
}


int maxHistogram(const vector<int> &hist) {
  const int m = hist.size();
  int mx=0;
  // 3, 1, 3, 2, 2
  for (int i=0; i<m; i++) {
    int val=hist[i];
    int l=i, r=i;
    // expand left boundary:
    while (l-1>=0 && hist[l-1]>=val) l--;
    // expand right boundary:
    while (r+1<m && hist[r+1]>=val) r++;

    int width=r-l+1;
    int area=width*val;
    mx=max(mx, area);
  }
  return mx;
}

int maximalAreaOfSubMatrixOfAll1_Hist1(vector<vector<int>> &mat, int n, int m) {
  int mx=0;
  vector<int> prev, cur(m, 0);
  for (int i=0; i<n; i++) {
    prev=cur;
    for (int j=0; j<m; j++) {
      cur[j]= mat[i][j]==0? 0 : prev[j]+1;
    }
    // cur is now a histogram
    mx=max(mx, maxHistogram(cur));
  }
  return mx;
}


#include <stack>
int maxHistogramFast(const vector<int> &hist) {
  const int m = hist.size();

  //    0  1  2  3  4
  //    3, 1, 3, 2, 2
  // lb 0  0  2  2  2
  // rb 0  5  2  4  4

  vector<int> lb (m, 0), rb (m, 0);
  stack<int> st;
  // find left boundary: prev smallest idx+1
  for (int i=0; i<m; i++) {
    while(!st.empty() && hist[st.top()] >= hist[i]) st.pop();
    int boundary= st.empty()? 0: st.top()+1;
    lb[i]=boundary;
    st.push(i);
  }

  int mx=0;
  st={}; // clear stack
  // find right boundary: next smallest idx-1
  for (int i=m-1; i>=0; i--) {
    while(!st.empty() && hist[st.top()] >= hist[i]) st.pop();
    int boundary= st.empty()? m-1: st.top()-1;
    rb[i]=boundary;
    st.push(i);

    // find max
    int width=rb[i]-lb[i]+1;
    int area=width*hist[i];
    mx=max(mx, area);
  }

  return mx;
}

int maximalAreaOfSubMatrixOfAll1_Hist2(vector<vector<int>> &mat, int n, int m) {
  int mx=0;
  vector<int> prev, cur(m, 0);
  for (int i=0; i<n; i++) {
    prev=cur;
    for (int j=0; j<m; j++) {
      cur[j]= mat[i][j]==0? 0 : prev[j]+1;
    }
    // cur is now a histogram
    mx=max(mx, maxHistogramFast(cur));
  }
  return mx;
}



#include "test/dp055.h"
int main() {
  run_tests("BF", maximalAreaOfSubMatrixOfAll1BF);
  run_tests("Hist1", maximalAreaOfSubMatrixOfAll1_Hist1);
  run_tests("Hist2", maximalAreaOfSubMatrixOfAll1_Hist2);
  // run_tests("BU", maximalAreaOfSubMatrixOfAll1BU);
  // run_tests("OPT", maximalAreaOfSubMatrixOfAll1OPT);

  print_report();
  return 0;
}