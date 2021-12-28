#ifndef RPL_DS_08_TEST_06_H_
#define RPL_DS_08_TEST_06_H_

#include <iostream>
#include <utility>
#include <vector>

bool error = false;
void test(string path, const vector<pair<string, bool>>& tests) {
  cout << "PATH: " << path << endl << endl;
  auto trie = new Trie();
  trie->insert(path);
  for (auto test: tests) {
    bool res = trie->has_path(test.first);
    error|=res!=test.second;
    cout << "exists: " << test.first << (res?" yes": "  no") << (res!=test.second? " (WRONG)":"") << endl;
  }
}

void test1() {
  string path {"user/noah/home"};
  vector<pair<string,bool>> tests {
      {"user", true},
      {"use", false},
      {"user/noah", true},
      {"user/noa", false},
      {"user/noahf", false},
      {"user/noah/home", true},
      {"user/noah/home/", true},
      {"user/noah/home/folder", false},
  };

  test(path, tests);
}

void test2() {
  string path {"/user/noah/home"};
  vector<pair<string,bool>> tests {
      {"/", true},
      {"user", false},
      {"user/noah", false},
      {"user/noah/home/", false},
      {"/user", true},
      {"/user/noah", true},
      {"/user/noah/home/", true},
      {"/user/noah/home///", true},
      {"/user/noah/home/fo", false},
  };

  test(path, tests);
}

void run_tests() {
  test1();
  test2();

  if (error) {
    cout << "\n\nERRORS FOUND\n";
  }
}



#endif  // RPL_DS_08_TEST_06_H_
