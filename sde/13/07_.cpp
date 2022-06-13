#include <stack>
using namespace std;

void insertSorted(stack<int> &st, int num) {
  if (st.empty() || num > st.top()) {
    // ascending. add it new num. it will become new top
    st.push(num);
    return;
  }

  // num is smaller than the top:
  // put num as deep as possible: swap with top and recur
  // deepest point: bottom of stack
  int tp = st.top(); st.pop();
  insertSorted(st, num);
  st.push(tp);
}

void sortStack(stack<int> &st) {
  if (st.empty()) return;

  // take out each number (on each recursive call)
  int num = st.top(); st.pop();
  sortStack(st);

  // insert that number sorted
  insertSorted(st, num);
}