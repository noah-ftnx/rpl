#include <iostream>
#include <vector>
using namespace std;

vector<int> sol1(vector<int>& vec) { // w/ division
 if (vec.size() < 2) return vec;

 int zero_count = 0;
 long prod_all = 1;
 for (int v : vec) {
   if (v == 0) {
     zero_count++;
   } else {
     prod_all *= v;
   }
 }

 vector<int> res(vec.size(), 0);
 if (zero_count > 1) return res;

 if (zero_count == 1) {
   for (int i=0; i<vec.size(); i++) {
     if (vec[i] == 0) res[i] = prod_all;
   }
   return res;
 }

 for (int i=0; i<vec.size(); i++) res[i] = prod_all / vec[i];
 return res;
}

vector<int> sol2(vector<int>& vec) { // w/o division
  if (vec.size() < 2) return vec;

  vector<int> res(vec.size(), 1);

  // 5, 2, 3, 4
  //
  // 0  5  5  5
  //       2  2
  //          3
  int tmp=1;
  for (int i=1; i<vec.size(); i++) {
    tmp*=vec[i-1];
    res[i]=tmp;
  }

  tmp=1;
  // 5, 2, 3, 4
  // 2  5  5  5
  // 3  3  2  2
  // 4  4  4  3
  for (int i=vec.size()-2; i>=0; i--) {
    tmp*=vec[i+1];
    res[i]*=tmp;
  }

  return res;
}

#include "test/002.h"
int main() { run_tests(); return 0; }