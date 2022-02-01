#include <vector>
#include <string>
using namespace std;

vector<string> substrings(string s) {
  vector<string> res;
  const int N = s.size();
  for (int i=0; i<N; i++) { // i: starting point
    for (int j=i; j<N; j++) { // j: ending point
      res.push_back(s.substr(i, j-i+1));
    }
  }
  return res;
}



#include "test/001.h"
int main() { run_tests(); return 0; }