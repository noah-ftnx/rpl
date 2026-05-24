#include <string>
#include <vector>
using namespace std;

int BF(const string& str, int i) {
  const int N = (int) str.size();
  if (N == 0) return 0;
  if (i == N) return 1;
  if (i > N || str[i] == '0') return 0;

  int res = BF(str, i+1);
  if (i+1 < N) {
    const int pair = (str[i]-'0')*10 + (str[i+1]-'0');
    if (pair >= 10 && pair <= 26) res += BF(str, i+2);
  }
  return res;
}

int decodings(string str) {
  if (str.empty()) return 0;

  const int N = (int) str.size();
  vector<int> dp(N+1, 0);
  dp[N] = 1;

  for (int i=N-1; i>=0; i--) {
    if (str[i] == '0') {
      dp[i] = 0;
      continue;
    }

    dp[i] = dp[i+1];
    if (i+1 < N) {
      const int pair = (str[i]-'0')*10 + (str[i+1]-'0');
      if (pair >= 10 && pair <= 26) dp[i] += dp[i+2];
    }
  }

  return dp[0];
}

#include "test/007.h"
int main() { run_tests(); return 0; }


// WRONG APPROACH: combinations:
// BRUTE-FORCE
// int combinations(string str, int i=0) {  // BF
//   if (i == str.size()) return 0; // base condition?
//   int res = 1;
//   if (str[i] <= 2 &&
//       i+1 < str.size() && str[i+1] <= 6) {
//     res+=1+combinations(str, i+2);
//   }
//   return res + combinations(str, i+1);
// }
//
// TOP-DOWN
// int _combinations_td(vector<int>& mmz, string str, int i) {  // TD
//   if (i == str.size()) return 0; // base condition?
//   if (mmz[i]!=-1) return mmz[i];
//   int res = 1;
//   if (str[i] <= 2 &&
//       i+1 < str.size() && str[i+1] <= 6) {
//     res+=1+_combinations_td(str, i+2);
//   }
//   res+=_combinations_td(str, i+1);
//   mmz[i]=res;
//   return res;
// }
//
// int combinations_td(string str, int i) {
//   vector<int>& mmz(str.size(), -1);
//   return _combinations_td(str, 0);
// }
//
//
// BOTTOM-UP
// int combinations_bu(string str) { // BU
//   vector<int> res(str.size()+1, 0);
//   for (int i=str.size()-1; i>=0; i--){
//     int score = res[i+1];
//     if (str[i]!='0') score++;
//     if (str[i] <=2 &&
//         (i+1 < str.size() && str[i+1] <=6)) {
//       score++;
//       score+=res[i+2];
//     }
//     res[i]=score;
//   }
//   return res[0];
// }