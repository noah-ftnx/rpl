
// IMPLEMENT: min_palindromeBF
string min_palindromeBF(string word);

// IMPLEMENT: min_palindromeMMZ
string min_palindromeMMZ(string word);

// IMPLEMENT: min_palindromeBU
string min_palindromeBU(string word);




#include "test/034.h"
int main() {
  run_tests("BF", min_palindromeBF);
  // run_tests("MMZ", min_palindromeMMZ);
  // run_tests("BU", min_palindromeBU);

  print_errors();
  return 0;
}