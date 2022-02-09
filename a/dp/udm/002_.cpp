#include <vector>
using namespace std;

int _max_passBF(const vector<int>& v, int i) {
  if (i >= v.size()) return 0; // empty or past last element
  return max(v[i] + _max_passBF(v, i+2), _max_passBF(v, i+1));
}
int max_passBF(const vector<int>& v) { return _max_passBF(v, 0); }



int _max_passTD(vector<int>& mmz, const vector<int>& v, int i=0) {
  if(i>=v.size()) return 0; // empty or past last element
  if (mmz[i] != -1) return mmz[i];

  int res = max(v[i] + _max_passTD(mmz, v, i+2),
                _max_passTD(mmz, v, i+1));

  mmz[i]=res;
  return res;
}

int max_passTD(const vector<int>& v) {
  vector<int> mmz(v.size(), -1);
  return _max_passTD(mmz, v);
}



int max_passBU(const vector<int>& v) {
  vector<int> res(v.size()+2, 0);
  for (int i=v.size()-1; i>=0; i--){
    res[i] = max(v[i]+res[i+2], res[i+1]);
  }
  return res[0];
}



int sol(const vector<int>& v) { // max_passBUopt
  int res, res1, res2;
  res=res1=res2=0;
  for (int i=v.size()-1; i>=0; i--) {
   res=max(v[i]+res2, res1);
   res2=res1;
   res1=res;
  }
  return res;
}





#include "test/002.h"
int main() {
  run_tests("BF", max_passBF);
  run_tests("TD", max_passTD);
  run_tests("BU", max_passBU);
  run_tests("sol", sol);
  return 0;
}