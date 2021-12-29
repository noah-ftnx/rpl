#ifndef RPL_DS_08_TEST_11_H_
#define RPL_DS_08_TEST_11_H_

#include <iostream>

void run_tests() {
  auto trie = Trie();
  trie.insert("abcd1");
  trie.insert("abcdef2");
  trie.insert("abcaa3");
  trie.insert("abaa4");
  trie.insert("abaathisthat5");
  trie.insert("ab6");
  trie.insert("ac7");
  trie.insert("acdd8");
  trie.insert("acdbdb9");

  string correct {
     "abaathisthat5\n"
      "abaa4\n"
      "ab6\n"
      "abcaa3\n"
      "abcdef2\n"
      "abcd1"};
  vector<string> r1;
  trie.autocomplete("ab", r1);
  cout << "autocomplete: \n";
  string result ="";
  for (const auto& r: r1) result+=r+"\n";
  result.pop_back();
  cout << result << (result!=correct? " (WRONG)":"") << endl;
}

#endif  // RPL_DS_08_TEST_11_H_
