#include <vector>
using namespace std;

int largestRectangleAreaBF(vector<int>& heights) {
  const int N = (int) heights.size();
  int mx=0;
  for (int i=0; i<N; i++) {
    int l=i, r=i;
    // find left boundary: GE than our height
    while(l-1>=0 && heights[l-1]>=heights[i]) l--;

    // find right boundary
    while(r+1<N && heights[r+1]>=heights[i]) r++;

    int width = r-l+1;
    int area = width*heights[i];
    mx=max(mx, area);
  }
  return mx;
}


#include <stack>
int largestRectangleAreaPass3(vector<int>& heights) {
  const int N = (int) heights.size();
  // left and right boundaries

  vector<int> lmin(N, -1), rmin(N, -1); // INDICES
  stack<int> st;

  // step1: fill left boundaries
  for (int i=0; i<N; i++) {
    // pop GE elements (useless if they are smaller than i
    while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();

    int boundary= st.empty()? 0 : st.top()+1;
    lmin[i]=boundary;
    st.push(i);
  }

  st={}; // clear stack

  // step2: fill right boundaries
  for (int i=N-1; i>=0; i--) {
    // pop GE elements
    while (!st.empty() && heights[st.top()]>=heights[i]) st.pop();

    int boundary= st.empty()? N-1 : st.top()-1;
    rmin[i]=boundary;
    st.push(i);
  }

  // find mx are
  int mx=0;
  for (int i=0; i<N; i++) {
    int width = rmin[i]-lmin[i]+1;
    int area = width*heights[i];
    mx=max(mx, area);
  }
  return mx;
}



int largestRectangleAreaPass2(vector<int>& heights) {
  const int N = (int) heights.size();
  // left and right boundaries

  vector<int> lmin(N, -1), rmin(N, -1); // INDICES
  stack<int> st;

  // step1: fill left boundaries
  for (int i=0; i<N; i++) {
    // pop GE elements (useless if they are smaller than i
    while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();

    int boundary= st.empty()? 0 : st.top()+1;
    lmin[i]=boundary;
    st.push(i);
  }

  st={}; // clear stack

  // step2: fill right boundaries & find mx
  int mx =0;
  for (int i=N-1; i>=0; i--) {
    // pop GE elements
    while (!st.empty() && heights[st.top()]>=heights[i]) st.pop();

    int boundary= st.empty()? N-1 : st.top()-1;
    rmin[i]=boundary;
    st.push(i);

    // find max:
    int width = rmin[i]-lmin[i]+1;
    int area = width*heights[i];
    mx=max(mx, area);
  }
  return mx;
}



int largestRectangleAreaPass1(vector<int>& heights) {
 const int N = (int) heights.size();

 stack<int> st;
 int mx=0;
 for (int i=0; i<=N; i++) {
   while(!st.empty() &&
          // last elements in stack or has GE elements
          (i==N || heights[st.top()] >= heights[i])) {
     // i: becomes rb for each of these
     int rb=i-1;

     int el=st.top(); st.pop();
     int lb= st.empty()? 0 : st.top()+1;
     int width=rb-lb+1;
     int area = width*heights[el];
     mx=max(mx, area);
   }
   st.push(i);
 }
 return mx;
}



#include "test/04.h"
int main() {
  run_tests("BF", largestRectangleAreaBF);
  run_tests("Pass3", largestRectangleAreaPass3);
  run_tests("Pass2", largestRectangleAreaPass2);
  run_tests("Pass1", largestRectangleAreaPass1);


  print_report();
  return 0;
}