#ifndef RPL_DS_08_TEST_11_H_
#define RPL_DS_08_TEST_11_H_

#include <iostream>
#include <set>

void run_tests() {
  auto trie = Trie();
  trie.insert("abcdz");
  trie.insert("abcdefo");
  trie.insert("abcaam");
  trie.insert("abaax");
  trie.insert("abaathisthate");
  trie.insert("abl");
  trie.insert("ace");
  trie.insert("acddi");
  trie.insert("acdbdbi");

  set<string> correct;
  correct.insert("abaathisthate");
  correct.insert("abaax");
  correct.insert("abl");
  correct.insert("abcaam");
  correct.insert("abcdefo");
  correct.insert("abcdz");

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
