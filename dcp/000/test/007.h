#ifndef RPL_DCP_TEST_007_H_
#define RPL_DCP_TEST_007_H_

#include <iostream>
#include <iomanip>

int decodings(string str);

bool _wrong=false;
void check(string input, int correct) {
  int result = decodings(input);
  bool wrong = result !=correct;
  _wrong|=wrong;
  cout << setw(7) << input << ": " << setw(4) << result << (wrong?" (WRONG)":"") << endl;
}

void print_errors() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
}

void run_tests() {
  check("", 0);
  check("1", 1);
  check("9", 1);
  check("19", 2);
  check("26", 2);
  check("27", 1);
  check("1010", 1);
  check("1020", 1);

  check("111", 3);

  check("127", 2);
  check("126", 3);
  check("1026", 2);

  check("222", 3);
  check("2222", 4);
  check("22222", 5);

  check("1234", 3);

  print_errors();
}



#endif  // RPL_DCP_TEST_007_H_
