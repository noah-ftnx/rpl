// INCLUDES
#include <vector>
#include <string>
using namespace std;

#include "test/007.h"

// BRUTE-FORCE TODO
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
// TOP-DOWN TODO
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
// BOTTOM-UP TODO
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

int to_int(char c) { return c-'0'; }

int decodings(string str) { // BU OPTIMIZED
  if (str.empty()) return 0;
  int score = 1;
  for (int i=str.size()-2; i>=0; i--) { // O(n)
    int val_i = str[i] - '0';
    int val_ip1 = str[i+1] - '0';

    if ((val_i == 1 && val_ip1 != 0) ||
        (val_i ==2 && val_ip1 <=6)) score++;
  }

  return score;
}



int main() {
  run_tests();
  return 0;
}