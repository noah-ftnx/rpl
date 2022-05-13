#include <string>
#include <vector>
using namespace std;

// 1-BASED INDEXING!
bool BF(int i, int j, const string &pattern, const string &text) {
  // base cases:
  // pattern consumed: text also has to be consumed to be true
  if (i==0) return j==0;
  else if (j==0) { // text consumed:
    // we can have any number of stars at j (only stars)..
    while (--i>=0) if (pattern[i]!='*') return false;
    return true;
  }

  const char pt=pattern[i-1];
  if (pt=='*') { // matching 0 or more chars

    // match 1 & allow re-matching
    bool match=BF(i, j-1, pattern, text);

    // skip star
    bool skip=BF(i-1, j, pattern, text);

    return (match |skip);
  } else { // might have to match or not
    // if a ?, it will match anyway. else chars must match
    bool matches = pt=='?' || pt==text[j-1];
    return matches && BF(i-1, j-1, pattern, text);
  }
}

bool wildcardMatchingBF(string pattern, string text) {
  const int P = (int) pattern.size();
  const int T = (int) text.size();

  return BF(P, T, pattern, text);
}



bool MMZ(int i, int j, const string &pattern, const string &text,
         vector<vector<int>> &dp) {
  // base cases:
  // pattern consumed: text also has to be consumed to be true
  if (i==0 ) return j==0;
  else if (j==0) { // text consumed:
    // we can have any number of stars at j (only stars)..
    while (--i>=0) if (pattern[i]!='*') return false;
    return true;
  } else if (dp[i][j]!=-1) return dp[i][j];

  const char pt=pattern[i-1];
  if (pt=='*') { // matching 0 or more chars

    // match 1 & allow re-matching
    bool match=MMZ(i, j-1, pattern, text, dp);

    // skip star
    bool skip=MMZ(i-1, j, pattern, text, dp);

    return dp[i][j]=(match |skip);
  } else { // might have to match or not
    // if a ?, it will match anyway. else chars must match
    bool matches = pt=='?' || pt==text[j-1];
    return dp[i][j]=(matches && MMZ(i-1, j-1, pattern, text, dp));
  }
}

bool wildcardMatchingMMZ(string pattern, string text) {
  const int P = (int) pattern.size();
  const int T = (int) text.size();
  vector<vector<int>> dp(P+1, vector<int>(T+1, -1));
  return MMZ(P, T, pattern, text, dp);
}



bool wildcardMatchingBU(string pattern, string text) {
  const int P = (int) pattern.size();
  const int T = (int) text.size();
  vector<vector<bool>> dp(P+1, vector<bool>(T+1, false));

  // base cases:
  dp[0][0]=true; // pattern consumed: text has to be consumed
                    // text was consumed: allowing only stars at the beginning
  for (int i=1; i<=P; i++) {
    // convert to 0-based index
    if (pattern[i-1]!='*') break;
    dp[i][0]=true;
  }

  for (int i=1; i<=P; i++) {
    for (int j=1; j<=T; j++) {
      const char pt=pattern[i-1];
      if (pt=='*') { // matching 0 or more chars

        // match 1 & allow re-matching
        bool match=dp[i][j-1];

        // skip star
        bool skip=dp[i-1][j];

        dp[i][j]=(match |skip);
      } else { // might have to match or not
        // if a ?, it will match anyway. else chars must match
        bool matches = pt=='?' || pt==text[j-1];
        dp[i][j]=(matches && dp[i-1][j-1]);
      }
    }
  }
  return dp[P][T];
}



bool wildcardMatchingOPT(string pattern, string text) {
  const int P = (int) pattern.size();
  const int T = (int) text.size();
  vector<bool> prev, cur(T+1, false);

  // base cases:
  cur[0]=true; // pattern consumed: text has to be consumed

  bool frontStars=true;
  for (int i=1; i<=P; i++) {
    prev=cur;
    // base case:
    // text consumed: allowing only stars in front
    if (frontStars && pattern[i-1]=='*') {
      cur[0]=true;
    } else {
      frontStars=false;
    }

    for (int j=1; j<=T; j++) {
      const char pt=pattern[i-1];
      if (pt=='*') { // matching 0 or more chars

        bool match=cur[j-1];  // match 1 & allow re-matching

        bool skip=prev[j]; // skip star

        cur[j]=(match |skip);
      } else { // might have to match or not
        // if a ?, it will match anyway. else chars must match
        bool matches = pt=='?' || pt==text[j-1];
        cur[j]=(matches && prev[j-1]);
      }
    }
  }
  return cur[T];
}



#include "test/dp034.h"
int main() {
  run_tests("BF", wildcardMatchingBF);
  run_tests("MMZ", wildcardMatchingMMZ);
  run_tests("BU", wildcardMatchingBU);
  run_tests("OPT", wildcardMatchingOPT);

  print_report();
  return 0;
}