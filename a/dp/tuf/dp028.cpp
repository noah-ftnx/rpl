
int longestPalindromeSubseqBF(string s);

int longestPalindromeSubseqMMZ(string s);

int longestPalindromeSubseqBU(string s);

int longestPalindromeSubseqOPT(string s);



#include "test/dp028.h"
int main() {
  run_tests("NaiveBF", longestPalindromeSubseqNaiveBF);
  // run_tests("BF", longestPalindromeSubseqBF);
  // run_tests("MMZ", longestPalindromeSubseqMMZ);
  // run_tests("BU", longestPalindromeSubseqBU);
  // run_tests("OPT", longestPalindromeSubseqOPT);

  print_report();
  return 0;
}