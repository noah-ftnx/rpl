
string min_palidromeBF(string word);

string min_palidromeMMZ(string word);

string min_palidromeBU(string word);


int main() {
  run_tests("BF", min_palidromeBF);
  // run_tests("MMZ", min_palidromeMMZ);
  // run_tests("BU", min_palidromeBU);

  print_errors();
  return 0;
}