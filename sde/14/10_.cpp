#include <stack>
using namespace std;

int findCelebrityBF(int n) {
  for (int i=0; i<n; i++) { // is i a celebrity?

    bool knownByAll=true, knowsNone=true;
    for (int j=0; (knownByAll && knowsNone) && j<n; j++) {
      if (j==i) continue;

      // i must be known by all
      if (!knows(j, i)) knownByAll=false;

      // i must know no one
      if (knows(i, j)) knowsNone=false;
    }

    if (knownByAll && knowsNone) return i;
  }
  return -1;
}


int findCelebrityOPT(int n) {
  stack<int> st;
  for (int i=0; i<n; i++) st.push(i);

  // eliminate candidates in pairs
  while(st.size()>1) {
    int c1 = st.top(); st.pop();
    int c2 = st.top(); st.pop();

    if (knows(c1, c2)) { // c1 can't be a candidate (knows someone)
      st.push(c2); // but c2 might be
    } else {  // c2 can't be a candidate (not known by all)
      st.push(c1); // but c1 might be
    }
  }

  int candidate=st.top(); st.pop();

  // someone that does not know someone else
  // or someone that is known by others
  // check: does it know anyone?
  for (int i=0; i<n; i++) {
    if (i==candidate) continue;
    if (knows(candidate, i) // knows someone
        || !knows(i, candidate) // or not known by someone
        ) return -1;

  }
  return candidate;
}
