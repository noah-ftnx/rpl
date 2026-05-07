#ifndef RPL_DS_08_TEST_09_H_
#define RPL_DS_08_TEST_09_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool _wrong {};

void test(string name, vector<string> dictionary, string prefix, string suffix, int correct) {
  auto trie = WordFilter(dictionary);
  int idx = trie.f(prefix, suffix);
  bool wrong = idx != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(16) << name;
  cout << "match: "  << (idx != -1 ? dictionary[idx] : "-1");
  if (wrong) cout << " (WRONG. Expected: " << correct << ")";
  cout << endl;
}

void run_tests() {
  test("suffix match", {"baaea", "apple", "bananax", "apple", "baaaa"}, "b", "x", 2);
  test("no suffix", {"baaea", "apple", "banana", "apple"}, "b", "x", -1);
  test("largest index", {"baaea", "apple", "banana", "apple"}, "b", "a", 2);
  test("earlier match", {"baaea", "apple", "bananax"}, "b", "a", 0);
  test("long suffix", {"baaea", "apple", "bananaex"}, "b", "aex", 2);
  test("one letter", {"a"}, "a", "a", 0);
  test("full prefix", {"apple"}, "apple", "e", 0);
  test("duplicate", {"apple", "x", "apple"}, "app", "e", 2);
  test("empty dict", {}, "", "", -1); // not allowing empty prefix / suffix

  cout << endl;
}

#endif  // RPL_DS_08_TEST_09_H_
