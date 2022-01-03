#ifndef RPL_DS_08_TEST_12_H_
#define RPL_DS_08_TEST_12_H_

#include <iostream>

bool _wrong=false;

void check(TST& trie, string s, bool correct) {
  bool result = trie.find(s);
  _wrong|=(result!=correct);

  cout << "has '" << s << "': " << boolalpha << result
       << (result!=correct?" (WRONG)":"") << endl;
}

void run_tests() {
  TST ternary = TST();
  ternary.insert("call");
  ternary.insert("me");
  ternary.insert("mind");
  ternary.insert("mid");

  check(ternary, "ca", false);
  check(ternary, "", false);
  check(ternary, "cal", false);
  check(ternary, "call", true);
  check(ternary, "call ", false);
  check(ternary, "me", true);
  check(ternary, "mid", true);
  check(ternary, "midd", false);
  check(ternary, "mind", true);
  cout << "\nremoving: mind, mind, mid\n";
  ternary.remove("mind");
  ternary.remove("mind");
  ternary.remove("mid");
  check(ternary, "mid", false);
  check(ternary, "mind", false);


  if (_wrong) { cout << "\n\nErrors found!\n"; }
}

#endif  // RPL_DS_08_TEST_12_H_
