
// IMPLEMENT: longest_palidromeBF
string longest_palidromeBF(string input);

// IMPLEMENT: longest_palidromeBU
string longest_palidromeBU(string input);

// IMPLEMENT: longest_palindrome
string longest_palindrome(string input);



#include "test/046.h"
int main() {
  run_tests("BF", longest_palidromeBF);
  run_tests("BU", longest_palidromeBU);
  run_tests("middle-expansion", longest_palindrome);

  print_errors();
  return 0;
}