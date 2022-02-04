#include <cmath>
#include <vector>
using namespace std;

int max_at(vector<int> input, int i) {
  if (i==0) return max(0, input[0]); // base case
  return max(input[i], input[i]+max_at(input, i-1));
}

int max_sumBF(const vector<int>& input) {
  const int N = input.size();
  int mx=0;
  for (int i=0; i<N; i++) {
    mx=max(mx, max_at(input, i));
  }
  return mx;
}


int max_atTD(vector<int> input, int i, vector<int>& mmz) {
  if (i==0) return input[0]; // base case
  else if (mmz[i] != INT_MIN) return mmz[i];
  mmz[i] =max(input[i], input[i]+max_atTD(input, i-1, mmz));
  return mmz[i];
}

int max_sumTD(const vector<int>& input) {
  const int N = input.size();
  vector<int> mmz(N, INT_MIN);
  int mx=0;
  for (int i=0; i<N; i++) {
    mx=max(mx, max_atTD(input, i, mmz));
  }
  return mx;
}

int max_sumBU(const vector<int>& input) {
  const int N = input.size();
  vector<int> tab(N, 0);
  tab[0]=max(0, input[0]);
  int mx=max(0, tab[0]);
  for (int i=1; i<N; i++) {
    tab[i]=max(input[i], input[i]+tab[i-1]) ;
    mx=max(mx, tab[i]);
  }
  return mx;
}

int max_sumOPT(const vector<int>& vec) {
  int global=0, local = 0;
  for (int i=0; i<vec.size(); i++) {
    local = max(vec[i], vec[i] + local);
    global = max(global, local);
  }
  return global;
}



#include "test/049.h"
int main() {
  run_tests("BF", max_sumBF);
  run_tests("MMZ", max_sumTD);
  run_tests("BU", max_sumBU);
  run_tests("OPT", max_sumOPT);
  return 0;
}