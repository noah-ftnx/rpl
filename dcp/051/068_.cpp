#include <utility>
#include <vector>
using namespace std;

int bishop_attacksBF(vector<pair<int,int>> bishops, const int M) {
  const int N = (int) bishops.size();

  auto is_attacking = [&] (pair<int, int> b1, pair<int, int> b2) {
    return abs(b1.first-b2.first) == abs(b1.second-b2.second);
  };

  int cnt{0};
  for (int i=0; i<N; i++) {
    for (int j=i+1; j<N; j++) { // every other bishop
      if (is_attacking(bishops[i], bishops[j])) cnt++;
    }
  }
  return cnt;
}

#include <unordered_map>
int bishop_attacks(vector<pair<int,int>> bishops, const int M) {
  const int N = (int) bishops.size();

  // diagonal -> sum
  unordered_map<int, int> mp_pdiag, mp_ndiag;

  auto increase_map = [] (unordered_map<int, int> &mp, int diag_id) {
    if (mp.contains(diag_id)) mp[diag_id]+=1;
    else mp.insert({diag_id, 1});
  };

  for (auto bishop: bishops) {
    int row=bishop.first, col=bishop.second;

    int pos_diag = col-row;
    int neg_diag = M-row-col;

    increase_map(mp_pdiag, pos_diag);
    increase_map(mp_ndiag, neg_diag);
  }

  auto pick_n_minus1 = [] (int n) { return (n*(n-1))/2; };

  int res{0};
  // for each diag: from N cnt, choose N-1
  for (auto cnt: mp_pdiag) res+= pick_n_minus1(cnt.second);
  for (auto cnt: mp_ndiag) res+= pick_n_minus1(cnt.second);

  return res;
}




#include "test/068.h"
int main() { run_tests(); return 0; }