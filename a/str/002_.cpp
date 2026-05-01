#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

int count_anagram_substrings(string s) {
  const int S = s.size();
  unordered_set<string> unq;
  vector<string> substrs;
  for (int i=0; i<S; i++) {
    for (int j=i; j<S; j++) {
      string substr(s.begin()+i, s.begin()+j+1);
      sort(substr.begin(), substr.end());
      unq.insert(substr);
    }
  }
  return unq.size();
}

#include "test/002.h"
int main() { run_tests(); return 0; }
