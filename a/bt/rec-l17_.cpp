#include <vector>
#include <string>
using namespace std;

void solve(string s,
           vector<vector<string>> &res, vector<string> &cur, int startIdx) {
  const int N = s.size();

  auto isPalindrome = [&] (int l, int r) {
    while (l<r) if (s[l++]!=s[r--]) return false;
    return true;
  };

  if (startIdx == N) {
    res.push_back(cur);
    return;
  }

  for (int i=startIdx; i<N; i++) {
    if (isPalindrome(startIdx, i)) {
      cur.push_back(s.substr(startIdx, i-startIdx+1));
      solve(s, res, cur, i+1);
      cur.pop_back();
    }
  }
}

vector<vector<string>> partition(string s) {
  vector<vector<string>> res; vector<string> cur;
  solve(s, res, cur, 0);
  return res;
}



#include "test/rec-l17.h"
int main() { run_tests(); return 0; }