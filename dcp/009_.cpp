#include <iostream>
#include <vector>
using namespace std;

// CHECK: prob it's solved. aircraft landing problem..
int sum_of_non_adjacent(const vector<int>& vec) {
  if (vec.size()<=1) return 0;

  int res1=0, res2=0, res=0;
  res1 = vec[vec.size()-1];
  for (int i=vec.size()-2; i>=0; i--) {
    res = vec[i];
    if(i+2 < vec.size()) {
      res+=res2;
    }
    res = max(res, res1);
    res2=res1;
    res1=res;
  }

  return res;
}


#include "test/009.h"
int main() { run_tests(); return 0; }