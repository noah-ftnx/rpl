#ifndef RPL_DCP_TEST_034_H_
#define RPL_DCP_TEST_034_H_

#include <iostream>
#include <iomanip>

string prototype(string word);
using fptr = decltype(prototype);


bool _wrong{};
void test(fptr function, string s, string correct) {
  string result = function(s);
  bool wrong = result !=correct;
  _wrong|=wrong;
  cout << setw(10) << s << ": additions: "  << setw(10) << result <<
      (wrong? " (WRONG)":"") << endl;
}


#include <sstream>

void pretty_tabulation(string word, const vector<vector<string>>& table) {
  vector<string> pallidromes;
  vector<stringstream> lines(word.size()+1);
  cout << endl;
  for (int j=0; j<=word.size(); j++) {
    for (int i=0; i<=word.size(); i++) {
      string s =table[i][j].empty() ? "--":table[i][j];
      if (s!="--" && s.size() > 1) {
        pallidromes.push_back(s);
        s=to_string(pallidromes.size());
      }
      lines[i] << setw(2) << s << " ";
    }

    // cout << endl;
  }
  for (int i=0; i<lines.size(); i++) cout << lines[i].str() << endl;
  cout <<endl;

  for (int i=0; i<pallidromes.size(); i++) {
    cout << setw(2) << to_string(i+1) << ": " << pallidromes[i] << endl;
  }
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";
  test(function, "ab", "aba");
  test(function, "aa", "aa");
  test(function, "", "");
  test(function, "abcd", "abcdcba");
  test(function, "abcda", "abcdcba");
  test(function, "abcde", "abcdedcba");
  test(function, "race", "ecarace");
  test(function, "google", "elgoogle");
  cout << endl;
}

void print_errors() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
}

#endif  // RPL_DCP_TEST_034_H_
