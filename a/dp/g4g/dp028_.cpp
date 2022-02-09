#include <string>
#include <vector>
using namespace std;

int BF(string word, int i, int j) { // O(3^N)
  if (i>=j) return 0; // empty word

  if (word[i]==word[j]) return BF(word, i+1, j-1);
  else {
    return 1 + min(BF(word, i+1, j),
                   BF(word, i, j-1));
  }
}

int min_additionsBF(string word) {
  return BF(word, 0, word.size()-1);
}


int MMZ(string word, int i, int j, vector<vector<int>>& mmz) {
 if (i>=j)  return 0; // empty word
 if (mmz[i][j] != -1) return mmz[i][j];

 int result;
 if (word[i]==word[j]) result = MMZ(word, i+1, j-1, mmz);
 else {
   result = 1 + min(MMZ(word, i+1, j, mmz),
                    MMZ(word, i, j-1, mmz));
 }
 mmz[i][j]=result;
 return result;
}

int min_additionsMMZ(string word) {
  vector<vector<int>> mmz(word.size(), vector<int>(word.size(), -1));
  return MMZ(word, 0, word.size()-1, mmz);
}


int min_additionsBU(string word) {
  if (word.empty()) return 0;

  vector<vector<int>> tab(word.size(), vector<int>(word.size(), 0));
  // R: result. depends on a, b, c
  //   a  b  c
  // a    c  R
  // b    a  b
  // c
  for (int i=word.size()-1; i>=0; i--){
    for (int j=0; j<word.size(); j++){
      if (i>=j) continue;
      else {
        if (word[i]==word[j]) {
         tab[i][j]=tab[i+1] [j-1]; // a
        } else {
          tab[i][j]=1+min(tab[i+1][j], tab[i][j-1]); // b, c
        }
      }
    }
  }

  return tab[0][word.size()-1];
}

int min_additionsOPT(string word) {
  if (word.empty()) return 0;

  // we only need 2 rows (size O(2N))
  vector<int> prev(word.size(), 0);
  vector<int> cur(word.size(), 0);

  // R: result. depends on a, b, c
  //   a  b  c
  // a    c  R
  // b    a  b
  // c
  for (int i=word.size()-1; i>=0; i--){
    swap(prev, cur);
    for (int j=0; j<word.size(); j++){
      if (i>=j) continue;
      else {
        if (word[i]==word[j]) {
          cur[j]=prev[j-1]; // a
        } else {
          cur[j]=1+min(prev[j], cur[j-1]); // b, c
        }
      }
    }
  }

  return cur[word.size()-1];
}



#include "test/028.h"
int main() {
  run_tests("BF", min_additionsBF);
  run_tests("MMZ", min_additionsMMZ);
  run_tests("BU", min_additionsBU);
  run_tests("OPT", min_additionsOPT);

  print_errors();
  return 0;
}