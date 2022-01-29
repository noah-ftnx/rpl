#include <string>
#include <vector>
using namespace std;

bool is_pallidrome(const string& word) {
  for (int i=0, j=word.size()-1; i<j; i++,j--) {
    if (word[i] != word[j]) return false;
  }
  return true;
}


string min_palidromeBF(string word) {
  if (is_pallidrome(word)) return word; // base case: found it, stop searching

  const int sz=word.size();
  const int last=sz-1;
  if (word[0]==word[last]) {  // match: isolate and recur:
    // aBFDa: a + MIDDLE + a
    return word[0] + min_palidromeBF(word.substr(1, sz-2)) + word[last];
  } else {
    // 2 cases:
    // 2.1 add to the right
    // ab: a + "b" + a
    string AL = word[0] + min_palidromeBF(word.substr(1, sz-1)) + word[0];
    // 2.2 add to the left
    // ba: a + "b" + a
    string AR = word[last] + min_palidromeBF(word.substr(0, sz-1)) + word[last];

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
string min_palidromeMMZ(string word) {
  static unordered_map<string, string> mmz;

  if (mmz.contains(word)) return mmz[word];

  if (is_pallidrome(word)) { mmz[word]=word; return word; } // base case: found it, stop searching

  const int sz=word.size();
  const int last=sz-1;
  string result;
  if (word[0]==word[last]) {  // match: isolate and recur:
    // aBFDa: a + MIDDLE + a
    result = word[0] + min_palidromeBF(word.substr(1, sz-2)) + word[last];
  } else {
    // 2 cases:
    // 2.1 add to the right
    // ab: a + "b" + a
    string AL = word[0] + min_palidromeBF(word.substr(1, sz-1)) + word[0];
    // 2.2 add to the left
    // ba: a + "b" + a
    string AR = word[last] + min_palidromeBF(word.substr(0, sz-1)) + word[last];

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
string min_palidromeBU(string word) { // O(N^3)
  vector<vector<string>> table(word.size()+1, vector<string>(word.size()+1));


  // row 0: empty strings: 0 char palindrome
  // tab[0][i]: "" (already set)
  // row 1: 1 char palindrome
  for (int i=0; i<word.size(); i++) {
    table[i][1] = word[i];
  }

  // j: palindrome words of size j
  // we need: the next i (row), and the previous j
  // so the fill order is like this
  // 1 4 6
  // 2 5
  // 3
  // words of size 0, 1 already in place
  // now find each word from size >=2
  for (int j=2; j<=word.size(); j++) {
    // test substrings from 0 to size-j of size j
    for (int i=0; i<=word.size()-j; i++) {
      string term = word.substr(i, j); // j is size: i+j-i=i
      const char first = term[0];
      const char last = term[j-1];
      string result;
      if (first==last) {
        result=first+table[i+1][j-2]+last;
      } else {
        string AL = first+table[i+1][j-1]+first;
        string AR = last+table[i][j-1]+last; // CHECK j-2?

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


int main() {
  run_tests("BF", min_palidromeBF);
  run_tests("MMZ", min_palidromeMMZ);
  run_tests("BU", min_palidromeBU);

  print_errors();
  return 0;
}