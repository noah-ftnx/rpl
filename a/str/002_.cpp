#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

int count_anagram_substrings(string s) {
  unordered_set<string> seen;
  const int N = s.size();

  for (int i=0; i<N; i++) {
    string key;
    for (int j=i; j<N; j++) {
      key += s[j];
      sort(key.begin(), key.end());
      seen.insert(key);
    }
  }

  return seen.size();
}

#include "test/002.h"
int main() { run_tests(); return 0; }
