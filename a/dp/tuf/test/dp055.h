#ifndef __H__
#define __H__

#include <string>
#include <iostream>
#include <iomanip>

int prototype(vector<vector<int>> &mat, int n, int m);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<vector<int>> mat, int correct) {
  int n = mat.empty()? 0 : mat.size();
  int m = mat.empty()? 0 : mat[0].size();
  auto result = function(mat, n, m);

  bool wrong = result != correct;
  _wrong|=wrong;
  cout << endl;
  string s="";
  for (auto row: mat) {
    for (auto i: row) s += to_string(i) + " ";
    s+="\n";
  }
  cout << (s.empty()?"{{}}\n":s);

  cout << "Area: " << setw(15) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, {}, 0);

  test(function, {{1,0,1,0,0},
                  {1,0,1,1,1},
                  {1,1,1,1,1},
                  {1,0,0,1,0}}, 6);

  test(function, {{1,0,1,1,1},
                  {1,0,1,1,1},
                  {1,1,1,1,1},
                  {1,0,0,1,1}}, 9);

  test(function, {{1,0,1,1,1},
                  {1,0,0,1,1},
                  {1,1,1,1,1},
                  {1,0,0,1,1}}, 8);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}



#endif  // __H__