
string min_palindromeBF(string word);

string min_palindromeMMZ(string word);

string min_palindromeBU(string word);




#include "test/034.h"
int main() {
  run_tests("BF", min_palindromeBF);
  // run_tests("MMZ", min_palindromeMMZ);
  // run_tests("BU", min_palindromeBU);

  print_errors();
  return 0;
}