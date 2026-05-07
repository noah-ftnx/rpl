#ifndef RPL_DS_08_TEST_04_H_
#define RPL_DS_08_TEST_04_H_

#include "../../../.inc/base.h"
#include <string>
#include <vector>
using namespace std;

string show(const vector<string>& vec) {
  string res = "[";
  for (int i = 0; i < vec.size(); i++) {
    if (i) res += ", ";
    res += vec[i];
  }
  res += "]";
  return res;
}

void check(string name, vector<string> input, vector<string> correct) {
  Trie trie;
  for (auto word: input) trie.insert(word);

  auto result = trie.get_words();
  bool wrong = result != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(18) << name;
  cout << setw(42) << show(input);
  cout << " -> " << show(result);
  if (wrong) cout << " (WRONG. Expected: " << show(correct) << ")";
  cout << endl;
}

void run_tests() {
  check("empty", {}, {});
  check("mixed", {"abcd", "xyz", "a", "ab", "xyzw", "bcd"}, {"a", "ab", "abcd", "bcd", "xyz", "xyzw"});
  check("prefix chain", {"abc", "a", "ab"}, {"a", "ab", "abc"});
  check("single", {"z"}, {"z"});
  cout << endl;
}

#endif  // RPL_DS_08_TEST_04_H_
