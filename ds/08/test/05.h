#ifndef RPL_DS_08_TEST_05_H_
#define RPL_DS_08_TEST_05_H_

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

bool _wrong {};

void test(Trie& trie, string suffix, bool correct) {
  bool result = trie.suffix_exists(suffix);
  bool wrong = result != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << "suffix: " << left << setw(10) << (suffix.empty() ? "\"\"" : suffix);
  cout << (result ? "true " : "false");
  if (wrong) cout << " (WRONG. Expected: " << (correct ? "true" : "false") << ")";
  cout << endl;
}

void run_tests() {
  auto trie = Trie();
  trie.insert("problem");
  trie.insert("system");
  trie.insert("trie");

  test(trie, "", false);
  test(trie, "y", false);
  test(trie, "p", false);
  test(trie, "m", true);
  test(trie, "em", true);
  test(trie, "lem", true);
  test(trie, "bem", false);
  test(trie, "problem", true);
  test(trie, "fproblem", false);
  test(trie, "tem", true);
  test(trie, "stem", true);
  test(trie, "ie", true);
  test(trie, "rie", true);
  test(trie, "xie", false);

  cout << endl;
}

#endif  // RPL_DS_08_TEST_05_H_
