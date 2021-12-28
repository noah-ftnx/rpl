#ifndef RPL_DS_08_TEST_09_H_
#define RPL_DS_08_TEST_09_H_

#include <iostream>

void test(vector<string> dictionary, string prefix, string suffix, int correct) {
  auto trie = WordFilter(dictionary);
  int idx = trie.f(prefix, suffix);

  cout << "match: " << (idx!=-1?dictionary[idx]:"-1") << (idx != correct? " (WRONG)":"") << endl;
}

void run_tests() {
  cout << __func__ << endl;
  test({"baaea", "apple", "bananax", "apple", "baaaa"}, "b", "x", 2);
  test({"baaea", "apple", "banana", "apple"}, "b", "x", -1);
  test({"baaea", "apple", "banana", "apple"}, "b", "a", 2);
  test({"baaea", "apple", "bananax"}, "b", "a", 0);
  test({"baaea", "apple", "bananaex"}, "b", "aex", 2);
  test({}, "", "", -1); // not allowing empty prefix / suffix
}

#endif  // RPL_DS_08_TEST_09_H_