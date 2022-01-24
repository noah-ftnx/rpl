

// line_limit: 10
// GREEDY:
// Isabel sat
// on the____
// step______
// Score          = 4+6
// Score=Spaces^2 = 16+36=52
// OPTIMAL:
// Isabel____
// sat on____
// the step__
// Score          = 4+4+2 = 10
// Score=Spaces^2 = 16+16+4=36


// Isabel sat on the step
// f(5): INF (out of bounds). base case.
// f(4): step______: 36

// f(3): the step__: SC: 4
//   or  the_______: 7^2 +
//       step______: (f4)

// f(2): on the step: SC: INF
//   or  on________: spaces^2 +
//       the step__: (f3)
//   or  on the____: 4^2 +
//       step______: (f4)


// f(1): sat on the step: SC: INF
//   or  sat_______: spaces^2 +
//       on the step: (f2)
//   or  sat on______: 4^2 +
//       the step______: (f3)
//   or  sat on the____: 4^2 +
//       step______: (f4)

// MINIMUM OF:
// f(0): Isabel sat on the step: SC: INF
//   or  0-0:1 word: spaces^2 +
//       rest: (f1)
//   or  0-1:2 words: 4^2 +
//       rest: (f2)
//   or  0-2:3 words: 4^2 +
//       rest: (f3)
//   or  4 words: 4^2 +
//       rest: (f4)
//   or  0-4:5 words: 0. stop condition. empty word
//                + f(5)


// i=size: return 0
// for j: i+1 <=size
// line_score(i, j-1) + f(j);

#include <climits>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

vector<string> breakup_text(string txt) {
  vector<string> r;
  istringstream iss(txt);
  string word;
  while (!iss.eof()) {
    iss >> word;
    r.push_back(word);
  }
  return r;
}

int line_score(int line_limit, int cur_line) {
  if (cur_line > line_limit) return INT_MAX;
  int diff = line_limit-cur_line;
  return diff*diff;
}

int line_chars(const vector<string>& words, int from, int to) {
  int len {};
  // to is inclusive
  // 0-1: count 0 index
  for (int i=from; i<to; i++) { len+=words[i].size(); }
  // spaces between all words except the last one
  len+=to-from-1;
  return len;
}

int formatBF(const vector<string>& words, const int& line_limit, int i) {
  if (i == words.size()) return 0;
  else {
    int score = INT_MAX;
    for (int j=i+1; j<=words.size(); j++) {
      int cur_line = line_chars(words, i, j);
      long local_score = (long) line_score(line_limit, cur_line) +
                         formatBF(words, line_limit, j);
      if (local_score > INT_MAX) local_score=INT_MAX;
      score=min(score, (int)local_score);
    }
    return score;
  }
}

int justifyBF(string text, const int& line_limit) {
  vector<string> words {breakup_text(text)};
  return formatBF(words, line_limit, 0);
}

int formatMMZ(const vector<string>& words, const int& line_limit, int i, vector<int>& mmz) {
  if (mmz[i] != -1) return mmz[i];
  int score = INT_MAX;
  for (int j=i+1; j<=words.size(); j++) {
    int cur_line = line_chars(words, i, j);
    long local_score = (long) line_score(line_limit, cur_line) +
                       formatMMZ(words, line_limit, j, mmz);
    if (local_score > INT_MAX) local_score=INT_MAX;
    score=min(score, (int)local_score);
  }
  mmz[i]=score;
  return score;
}

int justifyMMZ(string text, const int& line_limit) {
  vector<string> words {breakup_text(text)};
  vector<int> mmz(words.size()+1, -1);
  mmz[words.size()]=0; // base case
  return formatMMZ(words, line_limit, 0, mmz);
}

vector<vector<string>> justifyBU(string text, const int& line_limit) {
  vector<vector<string>> result;
  vector<string> words {breakup_text(text)};
  vector<int> scores(words.size()+1, 0);
  vector<int> line_breaks(words.size());

  // x x x 0
  for (int i=words.size()-1; i>=0; i--) {
    int score = INT_MAX;
    for (int j=i+1; j<=words.size(); j++) {
      int cur_line = line_chars(words, i, j);
      long lscore = (long) line_score(line_limit, cur_line) + scores[j];
      if (lscore > INT_MAX) lscore=INT_MAX; // overflow
      if (lscore < score) {
        score=(int) lscore;
        // [0, j1)
        // [j1, j2)
        line_breaks[i]=j;
      }
    }
    scores[i]=score;
  }

  for (int i=0; i<words.size();) {
    // include from: i to j0, then I want from j0 to j1
    result.push_back({words.begin()+i, words.begin()+line_breaks[i]});
    i=line_breaks[i];
  }

  return result;
}


vector<vector<int>> precompute_chars(const vector<string>& words) {
  vector<vector<int>> counts(words.size(), vector<int>(words.size(), 0));

  // vector is inclusive: [0][0], chars for only the 1st word
  // method was exclusive: count_chars(0, 1)
  for (int i=0; i<words.size(); i++) {
    for (int j=i; j<words.size(); j++) {
      counts[i][j]=words[j].size();
      if (j>i)  { // not the first word:
        // 1. previous words cost: [j-1]
        // 2. +1 for spaces cost: : M words need M-1 spaces between them
        counts[i][j]+=counts[i][j-1]+1;
      }
    }
  }

  // verify
  // for (int i=0; i<words.size(); i++) {
  //   for (int j=i; j<words.size(); j++) cout << counts[i][j] << " ";
  //   cout << endl;
  // }

  return counts;
}

vector<vector<string>> justifyOPT(string text, const int& line_limit) {
  vector<vector<string>> result;
  vector<string> words {breakup_text(text)};
  vector<vector<int>> char_counts({precompute_chars(words)});
  vector<int> scores(words.size()+1, 0);
  vector<int> line_breaks(words.size());

  for (int i=words.size()-1; i>=0; i--) {
    int score = INT_MAX;
    for (int j=i+1; j<=words.size(); j++) {
      int cur_line = char_counts[i][j-1];
      long lscore = (long) line_score(line_limit, cur_line) + scores[j];
      if (lscore > INT_MAX) lscore=INT_MAX; // overflow
      if (lscore < score) {
        score=(int) lscore;
        // [0, j1)
        // [j1, j2)
        line_breaks[i]=j;
      }
    }
    scores[i]=score;
  }

  for (int i=0; i<words.size();) {
    // include from: i to j0, then I want from j0 to j1
    result.push_back({words.begin()+i, words.begin()+line_breaks[i]});
    i=line_breaks[i];
  }
  return result;
}



#include "test/004.h"
int main() {
  run_tests_score("BF", justifyBF);
  run_tests_score("MMZ", justifyMMZ);
  run_tests("BU", justifyBU);
  run_tests("OPT", justifyOPT);

  return 0;
}