#include <vector>
#include <deque
#include <climits>
using namespace std;

vector<int> maxMinWindow(vector<int> a, int k) {
  /*
  n=3
  1 2 3 4
  1 1 1

    emit:
    1, 2
    mx: 1, 2
    answer is 2

    BF:
    max=INT_MIN:
    for each i: start from n
      min is i
      for each j: go back n
        - update min
      mx=max(mx, cur min)

      a * k

       k=3
       0 1 2 3
         .
       1 2 3 4
       1 1 1


       0 1 2 3 4 6 K=3
       3 5 2 1 5
       .

       - need min of each window

       DQ: use IDX
       2

       mx=INT_MIN;
       for each i until N:
           DQ: while not empty: and idx expired: pop FRONT
           - expired: dq.front() < i-k

           remove any bigger @idx: from BACK
           - while DQ not empty && a[i] <= a[back()]: pop BACK
           - this will leave smallest num on FRONT

           then take min:
           mn: @idx of FRONT


           if can emit: (i-k+1) >=0
             mx=max(mx, mn);

         return mx;

  */
  const int N = (int) a.size();
  deque<int> dq;
  int mx = INT_MIN;
  for (int i=0; i<N; i++) {
    // remove expired indices (have fallen out of the window)
    while(!dq.empty() && dq.front() < i-k) dq.pop_front();

    // remove any bigger values from the left
    while(!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();

    dq.push_back(i); // push idx
    int mn=dq.front();

    if (i-k+1 >=0) { // can emit
      mx=max(mx, mn);
    }
  }
  vector<int> res(mx);
  return res;
}


// LEFTHERE:
// MAKE TEST CASE OF THIS....... and verify
// online site does NOT work
// ALSO verify that this is the FASTEST approach.

#include "test/04.h"
int main() {
  run_tests("BF", largestRectangleAreaBF);
  run_tests("Pass3", largestRectangleAreaPass3);
  run_tests("Pass2", largestRectangleAreaPass2);
  run_tests("Pass1", largestRectangleAreaPass1);


  print_report();
  return 0;
}