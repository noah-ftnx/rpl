#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool word_exists(vector<vector<char>> grid, string word) {
  if (grid.empty() || word.empty()) return false;

  const int N=(int) grid.size();
  const int M=(int) grid[0].size();
  const int W=(int) word.size();


  // for each i,j
  for (int i=0; i<N; i++) {

    for (int j=0; j<M; j++) {

      bool matches=false;

      if (!matches && j+W <= M) { // fits horizontally
        matches = true; // assumption
        for (int k=0; matches && k<W; k++) matches = word[k]==grid[i][j+k];
      }


      if (i+W <= N) { // fits vertically
        matches = true; // assumption
        for (int k=0; matches && k<W; k++)  matches = word[k]==grid[i+k][j];
      }

      if (matches) return true;
    }
  }

  return false;
}




#include "test/063.h"
int main() { run_tests(); return 0; }