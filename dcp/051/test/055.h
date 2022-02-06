#ifndef RPL_DCP_051_TEST_055_H_
#define RPL_DCP_051_TEST_055_H_

#include <iostream>
#include <iomanip>

bool _wrong {};

string test_shorten(Shortener& s, string url) {
  auto code = s.shorten(url);
  cout << setw(25) << url << ": code: " << code;
  auto result = s.restore(code);

  cout << (result!=url? " (WRONG)":" (restore check passed)") << endl;
  return code;
}

void test() {
  Shortener s;
  string code1=test_shorten(s, "www.google.com");
  test_shorten(s, "www.amazon.com");
  test_shorten(s, "www.google.com/here");
  string code2=test_shorten(s, "www.google.com");
  cout << (code1!=code2? "WRONG: used different code for same url":"Correct. reused same code for same url.") << endl;

  test_shorten(s, "www.amazon.com");
}

void run_tests() {
  test();
}

#endif  // RPL_DCP_051_TEST_055_H_
