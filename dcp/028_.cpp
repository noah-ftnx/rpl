#include <vector>
#include <string>
using namespace std;

// Greedy:
vector<string> justify(vector<string> words, int k) {
  int sum {-1}; // 1st word: no space before
  vector<int> br;
  vector<int> sums;
  for (int i=0; i<words.size(); i++) { // O(W)
    int t = words[i].size()+1; // +1: for the including space.
    if (sum+t <= k) {
      sum+=t;
    } else {
      sums.push_back(sum);
      br.push_back(i); // break at i, exclusive
      sum=words[i].size(); // 1st word: no space
    }
  }
  // push the last sums+break
  sums.push_back(sum);
  br.push_back(words.size()); // exclusive, so size is OK.

  auto append_spaces = [](string& s, int spaces) {
    for (int i=0; i<spaces; i++) s+=" ";
  };

  vector<string> result;
  // 4 spaces: 2, by 2:
  for (int i=0; i<br.size(); i++) {
    int from = i==0? 0 : br[i-1];
    int to = br[i];

    int spaces_to_fill = k-sums[i];
    int words_num = to-from;

    string line;
    if (words_num==1) { // all spaces to the right
      line = words[from];
      append_spaces(line, spaces_to_fill);
    } else { // distribute spaces evenly, starting from the left
      int space_positions = words_num-1; // 3 words? spaces in 2 places
      // 7/2
      // 4, 1
      int even_spaces = spaces_to_fill/space_positions; // 4/2
      int extra_spaces = spaces_to_fill%space_positions;
      for (int j=from; j<to; j++) {
        line+=words[j];

        if (j!=to-1) { // not the last word
          append_spaces(line, 1);  // single-space, that was already accounted-for in sums
          append_spaces(line, even_spaces);
          // tricky: compare with > 0
          if (extra_spaces-- > 0) append_spaces(line, 1);
        }
      }
    }
    result.push_back(line);
  }
  return result;
}



#include "test/028.h"
int main () { run_tests(); return 0; }