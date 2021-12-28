#ifndef RPL_DS_08_TEST_08_H_
#define RPL_DS_08_TEST_08_H_

#include <iostream>

void test(string input, vector<string>& queries, string correct) {
  string res = "";
  auto substr=list_substrs(input, queries);
  for (auto r: substr) {
    res+= r + " ";
  }
  cout << "substrings: " << res << (res!=correct?" (WRONG)":"") << endl;
}

void test1() {
  string input = "aaaaaBBaaaaaCCCaaa";
  vector<string> queries {"BB", "C"};
  test(input, queries, "C BB ");
}

void test2() {
  string input = "heyabcdtwxyw";
  vector<string> queries {"xy", "ab", "t", "yz"};
  auto substr= list_substrs(input, queries);
  test(input, queries, "xy t ab ");
}


void run_tests() {
  test1();
  test2();
}

#endif  // RPL_DS_08_TEST_08_H_
