#ifndef RPL_DS_08_TEST_10_H_
#define RPL_DS_08_TEST_10_H_

#include <iostream>

void test(Trie& trie, string word, int mutations, bool correct) {
  bool result = trie.exists_with_mutations(word, mutations);
  cout << "'"<< word << "' with " << mutations << " mutations: "
       << boolalpha << result  << (result!=correct? " (WRONG)":"") << endl;
}

void run_tests() {
  cout << __func__ << endl;
  auto trie = Trie();
  trie.insert("hello");
  trie.insert("world");

  test(trie, "", 0, false);
  test(trie, "world", 0, true);
  test(trie, "world", 1, true);
  test(trie, "worx", 1, false);
  test(trie, "worxd", 1, true);
  test(trie, "worx", 2, true);
}

#endif  // RPL_DS_08_TEST_10_H_
