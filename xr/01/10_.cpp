using namespace std;
#include <vector>

vector<int> st(vector<vector<int>> input) {
  const int N = (int) input.size();
  const int M = (int) input[0].size();
  int size = N*M;
  vector<int> res (size);
  int C=0, R=0;

  int idx {}, i, j;
  while(idx < size) {
    // go right: change columns: (incl all nums)
    i=R;
    for (int j=C; j<M-C; j++) {
      res[idx++]=input[i][j];
    }

    // go down: move rows:
    j=M-1-C;
    for (int i=R+1; (idx<size) && i<N-R; i++) { // excl 1 num
      res[idx++]=input[i][j];
    }

    i=N-1-R;
    // go left: move columns
    for (int j=M-1-C-1; (idx<size) && j>=C; j--) { // excl 1 num
      res[idx++]=input[i][j];
    }

    // go up: move rows

    j=C;
    // exclude: bottom num and top num (2 nums)
    // 1st: -1 on init. 2nd: only greater than R (not GE)
    for (int i=N-1-R-1; (idx<size) && i>R; i--) {
      res[idx++]=input[i][j];
    }

    // must start over (preparation? overlapping indices?
    C++; R++;
  }

  return res;
}

// TODO