#include <vector>
#include <string>
using namespace std;

// ray ra. : 1
// raymont ra. : 0

// chat .hat : 1
// at *.at : 1
// ccchhat *.at : 1
// chats *.at : 0

// '' a*b*
// aaaab a*b*
// bbb a*b*

bool _BF(const string& input, const string& pattern, int i, int j) {
  auto next_is_star = [&]() { return j+1 < pattern.size() && pattern[j+1]=='*'; };
  auto match = [&]() {
    return i < input.size() && (pattern[j] == '.' || input[i]==pattern[j]);
  };

  // base cases
  if (j >= pattern.size() && i >= input.size()) return true;  // matched
  else if (j >= pattern.size()) return false; // consumed pattern, and there's still input
  // i == input.size: handled when a match is attempted
  // bbbbbb | b*a*

  if (next_is_star()) {
    return (match() && _BF(input, pattern, i+1, j)) // match a char
    || _BF(input, pattern, i, j+2); // empty match
  } else { // match and proceed
    return match() && _BF(input, pattern, i+1, j+1);
  }
}

bool matchBF(string input, string pattern) {
  return _BF(input, pattern, 0, 0);
}


bool _MMZ(const string& input, const string& pattern, int i, int j, vector<vector<short>>& mmz) {
  auto next_is_star = [&]() { return j+1 < pattern.size() && pattern[j+1]=='*'; };
  auto match = [&]() { return i < input.size() && (pattern[j]=='.' || input[i] == pattern[j]); };

  // base cases
  if (i >= input.size() && j >= pattern.size()) return true; // all consumed, matched.
  else if (j >= pattern.size()) return false; // not all of input consumed
  // else if: i == input.size(): some cases still true: aaaaa | a*b*

  if (mmz[i][j] != -1) return static_cast<bool>(mmz[i][j]);

  if (next_is_star()) {
    mmz[i][j] =
        (match() && _MMZ(input, pattern, i+1, j, mmz)) // match a char
        || _MMZ(input, pattern, i, j+2, mmz); // match empty char
  } else { // match and consume
    mmz[i][j] = match() && _MMZ(input, pattern, i+1, j+1, mmz);
  }
  return mmz[i][j];
}

bool matchMMZ(string input, string pattern) {
  vector<vector<short>> mmz(input.size()+1, vector<short>(pattern.size()+2, -1));
  return _MMZ(input, pattern, 0, 0, mmz);
}

bool matchTD(string input, string pattern) {
  auto current_is_star = [&](int j) { j--;
    return pattern[j]=='*';
  };
  auto match = [&](int i, int j) { i--; j--;
    return pattern[j]=='.' || pattern[j]==input[i];
  };

  vector<vector<bool>> tab(input.size()+1, vector<bool>(pattern.size()+1, false));


  // empty: input & pattern: T
  tab[0][0]=true;
  // (first col)
  // empty pattern: false, for remaining cases:

  // (first row)
  // empty input: true only up to the point that we accept an empty string.. a*bc
  // a*b*cccc
  for (int j=1; j<pattern.size(); j++) {
    // TRICKY: use lambda here as well.
    if (current_is_star(j)) tab[0][j]=tab[0][j-2];
  }

  for (int i=1; i<=input.size(); i++) {
    for (int j=1; j<=pattern.size(); j++) {
      if (current_is_star(j)) {
        // TRICKY: if the current is star, then match with the previous j
        tab[i][j]= (match(i, j-1) && tab[i-1][j]) || tab[i][j-2];
      } else {
        tab[i][j]=match(i, j) && tab[i-1][j-1];
      }
    }
  }

  return tab[input.size()][pattern.size()];
}


#include "test/025.h"
int main() {
  run_tests("BF", matchBF);
  run_tests("MMZ", matchMMZ);
  run_tests("TD", matchTD);
  return 0;
}