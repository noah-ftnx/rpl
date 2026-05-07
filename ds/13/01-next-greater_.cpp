#include <stack>
#include <vector>
using namespace std;

// For each value, replace it with the next greater value on its right.
// Use -1 if no greater value exists.
void find_next_greater_element(vector<int> &vec) {
  stack<int> st; // unresolved indices

  for (int i = 0; i < (int) vec.size(); i++) {
    while (!st.empty() && vec[i] > vec[st.top()]) {
      int idx = st.top();
      st.pop();
      vec[idx] = vec[i];
    }
    st.push(i);
  }

  while (!st.empty()) {
    vec[st.top()] = -1;
    st.pop();
  }
}

#include "test/01-next-greater.h"
int main() { run_tests(); return 0; }
