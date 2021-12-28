#ifndef RPL_LTCD_TEST_01_H_
#define RPL_LTCD_TEST_01_H_

#include <iostream>

void run_test(vector<string> dict, string sentence, string correct) {
  auto trie = new Solution();
  string result = trie->replaceWords(dict, sentence);
  cout << result << (result!=correct? " (WRONG)":"")<< endl;
}

void test1() {
  vector<string> dictionary {"cat","bat","rat"};
  string sentence = "the cattle was rattled by the battery";
  string correct = "the cat was rat by the bat";
  run_test(dictionary, sentence, correct);
}

void test2() {
  vector<string> dictionary = {"a","b","c"};
  string sentence = "aadsfasf absbs bbab cadsfafs";
  string correct = "a a b c";
  run_test(dictionary, sentence, correct);
}

void run_tests() {
  test1();
  test2();
}

#endif  // RPL_LTCD_TEST_01_H_
