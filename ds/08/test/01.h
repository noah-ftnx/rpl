#ifndef RPL_DS_08_TEST_01_H_
#define RPL_DS_08_TEST_01_H_

#include <iostream>

void check_word(Trie& trie, string word, bool correct) {
  bool res = trie.word_exists(word);
  cout << "  word: exists: " << word << ": " << res  << (res!=correct? " (WRONG)":"")<< endl;
}

void check_prefix(Trie& trie, string word, bool correct) {
  bool res = trie.prefix_exists(word);
  cout << "prefix: exists: " << word << ": " << res  << (res!=correct? " (WRONG)":"")<< endl;
}

void run_tests() {
  auto trie = Trie();
  string input = "abc";
  trie.insert(input);
  cout << "dictionary: " << input << endl;
  check_word(trie, "ab", false);
  check_prefix(trie, "ab", true);

  check_word(trie, "abc", true);
  check_prefix(trie, "abc", true);
}

#endif  // RPL_DS_08_TEST_01_H_
