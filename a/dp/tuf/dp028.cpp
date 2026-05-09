
// IMPLEMENT: longestPalindromeSubseqBF
int longestPalindromeSubseqBF(string s);

// IMPLEMENT: longestPalindromeSubseqMMZ
int longestPalindromeSubseqMMZ(string s);

// IMPLEMENT: longestPalindromeSubseqBU
int longestPalindromeSubseqBU(string s);

// IMPLEMENT: longestPalindromeSubseqOPT
int longestPalindromeSubseqOPT(string s);



#include "test/dp028.h"
int main() {
  run_tests("BF", longestPalindromeSubseqBF);
  // run_tests("MMZ", longestPalindromeSubseqMMZ);
  // run_tests("BU", longestPalindromeSubseqBU);
  // run_tests("OPT", longestPalindromeSubseqOPT);

  print_report();
  return 0;
}