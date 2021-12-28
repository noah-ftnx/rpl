#ifndef RPL_DS_08_TEST_05_H_
#define RPL_DS_08_TEST_05_H_

#include <iostream>
void test(Trie& trie, string suffix, bool correct) {
  bool result = trie.suffix_exists(suffix);
  cout << "suffix: " << suffix
       << (result? ": exists": "")
       << (result!=correct?" (WRONG)":"") << endl;
}

void run_tests() {
  auto trie = Trie();
  trie.insert("problem");

  // test(trie, "", false); // empty allowed?
  test(trie, "y", false);
  test(trie, "p", false);
  test(trie, "m", true);
  test(trie, "em", true);
  test(trie, "lem", true);
  test(trie, "bem", false);
  test(trie, "problem", true);
  test(trie, "fproblem", false);
}

#endif  // RPL_DS_08_TEST_05_H_
