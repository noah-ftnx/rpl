#include <vector>
using namespace std;

int BF(const vector<int> &input, int i, int lsel) {
  const int N = (int) input.size();
  if (i==N) return 0;

  // move on..
  if (lsel >=0 && input[i] < input[lsel]) return BF(input, i+1, lsel);
  else {
    return max(
        1+BF(input, i+1, i), // selecting i
        BF(input, i+1, lsel) // skipping i
    );
  }

}

int solveBF(vector<int> input) {
  return BF(input, 0, -1);
}

int MMZ(const vector<int> &input, int i, int lsel,
        vector<vector<int>>& mmz) {
  const int N = (int) input.size();
  if (i==N) return 0;
  else if (lsel>=0 && mmz[i][lsel]!=-1) return mmz[i][lsel];

  // move on..
  int res;
  if (lsel >=0 && input[i] < input[lsel]) {
    res=MMZ(input, i+1, lsel, mmz);
  } else {
    res= max(
        1+MMZ(input, i+1, i, mmz), // selecting i
        MMZ(input, i+1, lsel, mmz) // skipping i
    );
  }
  mmz[i][lsel]=res;
  return res;
}

int solveMMZ(vector<int> input) {
  const int N = (int) input.size();
  vector<vector<int>> mmz(N, vector<int>(N, -1));
  return MMZ(input, 0, -1, mmz);
}


int solveBU(vector<int> input) {
  const int N = (int) input.size();
  vector<vector<int>> tab(N+1, vector<int>(N+1, 0));

  for (int i=N-1; i>=0; i--) {
    for (int lsel=N; lsel>=i; lsel--) {
      int res;
      if (lsel < N && input[i] > input[lsel]) {
        res = tab[i + 1][lsel];
      } else {
        res = max(
            1 + tab[i + 1][i],  // selecting i
            tab[i + 1][lsel]    // skipping i
        );
      }
      tab[i][lsel]=res;
    }
  }

  return tab[0][0];
}




#include "test/075.h"
int main() {
  run_tests("BF", solveBF);
  run_tests("MMZ", solveMMZ);
  run_tests("BU", solveBU);
  // run_tests("OPT", fOPT);

  // print_errors();
  // print_report();
  return 0;
}