#ifndef RPL_DS_08_TEST_11_H_
#define RPL_DS_08_TEST_11_H_

#include <iostream>
#include <set>

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

  set<string> correct;
  correct.insert("abaathisthat5");
  correct.insert("abaa4");
  correct.insert("ab6");
  correct.insert("abcaa3");
  correct.insert("abcdef2");
  correct.insert("abcd1");

  vector<string> r1;
  trie.autocomplete("ab", r1);
  cout << "autocomplete: \n";
  set<string> result;
  for (const auto& r: r1) result.insert(r);

  string res;
  for (auto r: result) res+=r+"\n";
  bool wrong = (result!=correct);
  cout << res << (wrong? "\n\nWRONG.":"") << endl;
}

#endif  // RPL_DS_08_TEST_11_H_
