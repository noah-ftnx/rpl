#include <vector>
#include <string>
using namespace std;

string clockwise_spiral(vector<vector<int>> vec) {
  if (vec.empty()) return "";
  const int N = (int) vec.size();
  const int M = (int) vec[0].size();

  string res;

  auto prt = [&] (int val) { res+= to_string(val) + " "; };

  int L=0;
  while(true) {
    // 1: top column
    for (int j=L; j<M-L; j++) prt(vec[L][j]);

    // 2: right row
    for (int i=L+1; i<N-L; i++) prt(vec[i][M-1-L]);

    // 3: bottom column (reverse)
    for (int j=M-L-2; j>=L; j--) prt(vec[N-1-L][j]);

    // 4: left row (reverse + special)
    for (int i=N-L-2; i>L; i--) { // NOTICE: greater than L
      prt(vec[i][L]);
    }

    L++; // advance level

    if (L == N/2 || L == M/2) break;
  }

  return res;
}



#include "test/065.h"
int main() { run_tests(); return 0; }