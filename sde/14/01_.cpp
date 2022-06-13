#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n) {

  vector<int> res(n, -1);
  stack<int> st;
  for (int i=n-1; i>=0; i--) {
    // remove any previous elements that are bigger
    // (can't be part of cur solution,
    // and won't be part in the "future")
    while (!st.empty() && st.top() >= arr[i]) st.pop();

    res[i] = st.empty()? -1 : st.top();

    st.push(arr[i]);
  }

  return res;
}