
// IMPLEMENT: justifyBF
int justifyBF(string text, const int& line_limit);

// IMPLEMENT: justifyMMZ
int justifyMMZ(string text, const int& line_limit);

// IMPLEMENT: justifyBU
vector<vector<string>> justifyBU(string text, const int& line_limit);

// IMPLEMENT: justifyOPT
vector<vector<string>> justifyOPT(string text, const int& line_limit);



#include "test/004.h"
int main() {
  run_tests_score("BF", justifyBF);
  run_tests_score("MMZ", justifyMMZ);
  run_tests("BU", justifyBU);
  run_tests("OPT", justifyOPT);

  return 0;
}