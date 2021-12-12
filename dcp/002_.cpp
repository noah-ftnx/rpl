#include "test/test-002.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> sol1(vector<int>& vec) { // w/ division
 if (vec.size() < 2)  return vec;

 long prod_all=1;
 for(int i=0; i<vec.size(); i++) prod_all*=vec[i];

 vector<int> res(vec.size(), prod_all);
 for (int i=0; i<vec.size(); i++) res[i]/=vec[i];

 return res;
}

vector<int> sol2(vector<int>& vec) { // w/o division
  vector<int> res(vec.size());

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
  res[0]=tmp; // TRICKY
  for (int i=vec.size()-2; i>=0; i--) {
    tmp*=vec[i+1];
    res[i]*=tmp;
  }

  return res;
}

int main() { run_tests(); return 0; }
