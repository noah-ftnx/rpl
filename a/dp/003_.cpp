#include <vector>
using namespace std;

int max_at_idx_bf(const vector<int>& vec, int idx) {
  if(idx==0) return vec[0];
  return max(vec[idx], vec[idx]+ max_at_idx_bf(vec, idx-1));
}

int max_subarr_bf(const vector<int>& vec) {
  int res = 0;
  for (int i=vec.size()-1; i>=0; i--) {
    res = max(res, max_at_idx_bf(vec, i));
  }
 return res;
}

int max_at_idx_td(vector<int>& mmz, const vector<int>& input, int idx) {
  if(mmz[idx] != INT_MIN) return mmz[idx]; // covering base case: mmz[0]

  int res = max(input[idx], input[idx]+ max_at_idx_td(mmz, input, idx-1));
  mmz[idx]=res;
  return res;
}

int max_subarr_td(const vector<int>& vec) {
  vector<int> mmz(vec.size(), INT_MIN);
  mmz[0]=vec[0]; // tricky
  int res =0;
  for (int i=0; i<vec.size(); i++) {
    res = max(res, max_at_idx_td(mmz, vec, i));
  }
  return res;
}

int max_subarr_bu(const vector<int>& vec) {
  vector<int> i_max(vec.size(), 0);
  // fill i_max
  i_max[0]=vec[0];
  for (int i=1; i<vec.size(); i++) {
    i_max[i] = max(vec[i], vec[i] + i_max[i-1]);
  }

  int global = 0;
  for (int i=0; i<vec.size(); i++) {
    global = max(global, i_max[i]);
  }

  return global;
}

int sol(const vector<int>& vec) {
  int global=0, local = 0;
  for (int i=0; i<vec.size(); i++) {
    local = max(vec[i], vec[i] + local);
    global = max(global, local);
  }
  return global;
}

#include "test/003.h"
int main() {
  run_tests("bf", max_subarr_bf);
  run_tests("td", max_subarr_td);
  run_tests("bu", max_subarr_bu);
  run_tests("sol", sol);
  return 0;
}