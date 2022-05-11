#ifndef __H__
#define __H__

#include <iostream>
#include <iomanip>

string prototype(string s, string t);
using fptr = decltype(prototype);

bool prt_dp_=false;

void print_dp(string s, string t, const vector<vector<int>>& dp) {
  if (!prt_dp_) return;

  const int S = (int) s.size();
  const int T = (int) t.size();

  cout << "   ";
  for (int i=0; i<=S; i++)
    cout << setw(2) << (i==0? ' ' : (s[i-1])) << " ";
  cout << endl;

  int jRow=0;
  for (int i=0; i<=S; i++) {
    for (int j=0; j<=T; j++) {

      if (j==0) {
        // cout << setw(2) << (i==0? ' ' : t[j-1]) << " ";
        cout << setw(2) << (i==0? ' ':t[jRow++]) << " ";
      }

      cout << setw(2) << dp[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl << endl;
}


bool _wrong{};
void test(fptr function, string s, string t, string correct) {
  string result = function(s, t);
  bool wrong = result !=correct;
  _wrong|=wrong;
  cout << setw(10) << (s.empty()?"{}":s) << " " << setw(10) << (t.empty()?"{}":t) << " ";
  cout << "LCS: " << setw(5) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, "",  "", "");
  test(function, "acd", "ced", "cd");
  test(function, "adebe", "dcadb", "adb");
  test(function, "abcde", "bdgek", "bde");
  test(function, "xabc", "abcyyy", "abc");

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // __H__