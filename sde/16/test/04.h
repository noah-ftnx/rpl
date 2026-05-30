#ifndef RPL_SDE_16_TEST_04_H_
#define RPL_SDE_16_TEST_04_H_

#include <iostream>
#include <string>
using namespace std;

bool _wrong {};

void check(string name, string s, string t, bool correct) {
  Solution sol;
  bool got = sol.isAnagram(s, t);
  bool wrong = got != correct;
  _wrong |= wrong;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << name << endl;
}

void run_tests() {
  check("anagram", "anagram", "nagaram", true);
  check("not_equal", "rat", "car", false);
  check("same", "aa", "aa", true);
  check("length", "a", "ab", false);
  cout << endl;
}

#endif  // RPL_SDE_16_TEST_04_H_
