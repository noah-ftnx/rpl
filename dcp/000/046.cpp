
string longest_palidromeBF(string input);

string longest_palidromeBU(string input);

string longest_palindrome(string input);



#include "test/046.h"
int main() {
  run_tests("BF", longest_palidromeBF);
  run_tests("BU", longest_palidromeBU);
  run_tests("middle-expansion", longest_palindrome);

  print_errors();
  return 0;
}