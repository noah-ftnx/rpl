#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    const int S = s.size();
    const int T = t.size();
    if (S != T) return false;

    vector<int> st(26, 0);
    for (auto c: s) st[c-'a']++;
    for (auto c: t) st[c-'a']--;
    for (int n: st) if (n != 0) return false;
    return true;
  }
};

#include "test/04.h"
int main() { run_tests(); return 0; }
