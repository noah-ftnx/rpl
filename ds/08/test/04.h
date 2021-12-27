#ifndef RPL_DS_08_TEST_04_H_
#define RPL_DS_08_TEST_04_H_

#include <algorithm>
void run_tests() {
  cout << __func__ << endl;
  auto trie = Trie();

  vector<string> input {
      "abcd",
      "xyz",
      "a",
      "ab",
      "xyzw",
      "bcd"
  };

  for (auto word: input) {
    cout << word << " ";
   trie.insert(word);
  }
  cout << "| input.\n";

  auto result = trie.get_words();

  sort(input.begin(), input.end());
  string correct="";
  for (auto w: input) {
   cout << w  << " ";
   correct+=w + " ";
  }
  cout << "| input sorted." << endl;

  string tmp="";
  for (auto w: result) {
    cout << w  << " ";
    tmp+=w + " ";
  }
  cout << "| result." << (tmp!=correct? " (WRONG)":"") << endl;


}


#endif  // RPL_DS_08_TEST_04_H_
