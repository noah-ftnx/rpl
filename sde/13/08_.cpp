#include <vector>
using namespace std;

int findMaxBF(vector<int> &a, int n, int windowSize) {
  int mx=INT_MIN;

  for (int i=windowSize-1; i<n; i++) { // each valid window
    // find min in each window
    int mn = INT_MAX;
    for (int j=i; j>=(i-windowSize+1); j--) { // go back in the window
      mn=min(mn, a[j]);
    }
    mx=max(mx, mn);
  }

  return mx;
}

vector<int> maxMinWindowBF(vector<int> a, int n) {
  vector<int> res;

  for (int windowSize=1; windowSize<=n; windowSize++) {
    res.push_back(findMaxBF(a, n, windowSize));
  }

  return res;
}


#include <stack>
using namespace std;

vector<int> maxMinWindowOPT(vector<int> a, int n) {
  vector<int> prevLE(n);
  stack<int> st; // INDICES
  for (int i=0; i<n; i++) {
    // remove any smaller elements
    while(!st.empty() && a[i]  <= a[st.top()]) st.pop();

    prevLE[i]=st.empty()? 0:st.top()+1;

    st.push(i);
  }
  // 0, 0, 2, 0, 4

  st=stack<int>();
  vector<int> nextLE(n);
  for (int i=n-1; i>=0; i--) {
    // remove any smaller elements
    while(!st.empty() && a[i]  <= a[st.top()]) st.pop();

    nextLE[i]=st.empty()? n-1 : st.top()-1;

    st.push(i);
  }

  // now we can calcualte the ranges:
  // e.g. 4,4, must be 1: @nextLE-@prevLE+1
  vector<int> res(n, INT_MIN);
  for (int i=0; i<n; i++) {
    int range = nextLE[i]-prevLE[i]+1;
    // making range again 0 based
    res[range-1]=max(res[range-1], a[i]);
  }

  for (int i=n-2; i>=0; i--) {
    res[i]=max(res[i], res[i+1]);
  }

  return res;
}