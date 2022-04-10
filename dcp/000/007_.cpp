#include <string>
using namespace std;

int BF(string str, int i) {
  const int N = (int) str.size();
  if (N==0 && i>N) return 0;
  else if(i==N-1) return 1; // normal case

  const char cc = str[i]; // current char
  if (cc != '0') {
    if (i+1 < N) { // next char in bounds
      const char nc = str[i+1]; // next char
      if (nc != '0' && // '10', '20' ignored..
          cc == '1' || (cc =='2' && (nc >='1' && nc <='6'))
          ) {
        return 1+BF(str, i+1);
      }
    }
  }

  return BF(str, i+1);
}

int decodings(string str) {
  if (str.empty()) return 0;

  int res = 1;
  const int N = (int) str.size();
  for (int i=N-2; i>=0; i--) {
    const char cc = str[i];
    const char nc = str[i+1];
    if ((cc=='1' && nc != '0') ||
        (cc=='2' && nc >= '1' && nc <='6')) res ++;
  }

  return res;
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
