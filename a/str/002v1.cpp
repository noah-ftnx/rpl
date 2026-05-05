#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

int count_anagram_reorderings(string s) {
  unordered_set<string> unq;
  const int N = s.size();
  for (int i=0; i<N; i++) {
    for (int j=i; j<N; j++) {
      string cur(s.begin()+i, s.begin()+j+1);
      sort(cur.begin(), cur.end());
      do {
        unq.insert(cur);
      } while (next_permutation(cur.begin(), cur.end()));
    }
  }
  return unq.size();
}

#include "test/002v1.h"
int main() { run_tests(); return 0; }
