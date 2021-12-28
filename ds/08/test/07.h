#ifndef RPL_DS_08_TEST_07_H_
#define RPL_DS_08_TEST_07_H_

#include <iostream>
#include <vector>

void run_tests() {
  cout << __func__ << endl;
  auto trie = Trie();

  vector<string> input { "xyz","xyzeA","a","bc" };

  for (auto word: input) {
    cout << word << " ";
    trie.insert(word);
  }
  cout << "| input.\n";


  vector<string> test{ "", "x", "xyz" };
  vector<string> correct{ "", "x", "xyz" };
  for (int i=0; i<test.size(); i++) {
    auto t = test[i];
    auto c = correct[i];
    cout << "test: " << t  << ": ";
    string r = trie.minimal_prefix(t);
    cout << r  << (r!=c? " (WRONG)":"")<< endl;
  }
}


#endif  // RPL_DS_08_TEST_07_H_
