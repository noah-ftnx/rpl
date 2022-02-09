#include <string>
#include <vector>
using namespace std;

bool is_pallidrome(const string& word) {
  for (int i=0, j=word.size()-1; i<j; i++,j--) {
    if (word[i] != word[j]) return false;
  }
  return true;
}


string min_palindromeBF(string word) {
  if (is_pallidrome(word)) return word; // base case: found it, stop searching

  const int sz=word.size();
  const int last=sz-1;
  if (word[0]==word[last]) {  // match: isolate and recur:
    // aBFDa: a + MIDDLE + a
    return word[0] + min_palindromeBF(word.substr(1, sz-2)) + word[last];
  } else {
    // 2 cases:
    // 2.1 add to the right
    // ab: a + "b" + a
    string AL = word[0] + min_palindromeBF(word.substr(1, sz-1)) + word[0];
    // 2.2 add to the left
    // ba: a + "b" + a
    string AR = word[last] + min_palindromeBF(word.substr(0, sz-1)) + word[last];

    if (AL.size() == AR.size()) {
      // return lexicographically first
      for (int i=0; i<AL.size()/2; i++) {
        if (AL[i] == AR[i]) continue;
        else if (AL[i] < AR[i]) return AL;
        else return AR;
      }
      return AL;
    } else {
      return AL.size() < AR.size()? AL:AR;
    }
  }
}


#include <unordered_map>
string min_palindromeMMZ(string word) {
  static unordered_map<string, string> mmz;

  if (mmz.contains(word)) return mmz[word];

  if (is_pallidrome(word)) { mmz[word]=word; return word; } // base case: found it, stop searching

  const int sz=word.size();
  const int last=sz-1;
  string result;
  if (word[0]==word[last]) {  // match: isolate and recur:
    // aBFDa: a + MIDDLE + a
    result = word[0] + min_palindromeBF(word.substr(1, sz-2)) + word[last];
  } else {
    // 2 cases:
    // 2.1 add to the right
    // ab: a + "b" + a
    string AL = word[0] + min_palindromeBF(word.substr(1, sz-1)) + word[0];
    // 2.2 add to the left
    // ba: a + "b" + a
    string AR = word[last] + min_palindromeBF(word.substr(0, sz-1)) + word[last];

    if (AL.size() == AR.size()) {
      // return lexicographically first
      result = AL;
      for (int i=0; i<AL.size()/2; i++) {
        if (AL[i] == AR[i]) continue;
        else if (AL[i] < AR[i]) { break; }
        else { result=AR; break; }
      }
    } else {
      result = AL.size() < AR.size()? AL:AR;
    }
  }
  mmz[word]=result;
  return result;
}


#include "test/034.h"
string min_palindromeBU(string word) {
  const int N=word.size();
  vector<vector<string>> table(N+1, vector<string>(N+1));


  // palindromes of:
  // row 0: empty strings. palindromes of sz 0
  // row1: palindromes of sz 1
  for (int i=0; i<N; i++) table[i][1] = word[i];

  // i: from where the string starts
  // j: how many characters the palindrome has
  // j[0-1]: already set
  // we need: the next i (row), and the previous j
  // so the fill order is like this
  // 1 4 6
  // 2 5
  // 3
  // words of size 0, 1 already in place
  // now find each word from size >=2
  for (int j=2; j<=N; j++) {
    // test substrings from 0 to size-j of size j

    // sliding window:
    // build palindromes of j chars: e.g. j=3, N=4
    // 0 - 2
    //   1 - 3
    //     2 - 4
    // for each: we need the next i of prev col, or prev-prev col
    // col (j) is shifted by 1 to the left
    for (int i=0; i<=N-j; i++) {
      string term = word.substr(i, j); // j is size: i+j-i=i
      const char first = term[0];
      const char last = term[j-1];
      string result;
      if (first==last) {
        result=first+table[i+1][j-2]+last;
      } else {
        string AL = first+table[i+1][j-1]+first;
        string AR = last+table[i][j-1]+last;

        // shortest or lexicographically first
        if (AL.size() == AR.size()) {
          result = AL;
          for (int i=0; i<AL.size()/2; i++) {
            if (AL[i] == AR[i]) continue;
            else if (AL[i] < AR[i]) { break; }
            else { result=AR; break; }
          }
        } else {
          result = AL.size() < AR.size()? AL:AR;
        }
      }
      // cout << "Filling: ["  << i << "," << j << "]\n";
      table[i][j]=result;
    }
  }

  // pretty_tabulation(word, table);
  return table[0][word.size()];
}

#include "test/034.h"
int main() {
  run_tests("BF", min_palindromeBF);
  run_tests("MMZ", min_palindromeMMZ);
  run_tests("BU", min_palindromeBU);

  print_errors();
  return 0;
}