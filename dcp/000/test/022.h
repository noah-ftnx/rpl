#ifndef RPL_DCP_TEST_022_H_
#define RPL_DCP_TEST_022_H_

#include <iostream>

bool _wrong {};
void test(vector<string> dict, string input, vector<vector<string>> correct) {
  auto res = search_dict(dict, input);
  cout << "Result (" << res.size() << "):\n";
  for (auto r: res) {
    for (auto s: r) cout << s << " ";
    cout << endl;
  }

  bool wrong = correct !=res;
  _wrong=wrong;
  cout << (wrong? "WRONG.": "Correct.") << endl << endl;
}

void test1() {
  vector<string> dict {"quick", "brown", "the", "fox"};
  string input {"thequickbrownfox"};
  vector<vector<string>> correct { {"the", "quick", "brown", "fox"} };

  test(dict, input, correct);
}

void test2() {
 vector<string> dict {"bed", "bath", "bedbath", "and", "beyond"};
  string input {"bedbathandbeyond"};

  vector<vector<string>> correct {
      {"bed", "bath", "and", "beyond"},
      {"bedbath", "and", "beyond"}
  };

  test(dict, input, correct);
}

void run_tests() {
  test1();
  test2();

  if (_wrong) cout << "WRONG RESULTS.\n";
}

#endif  // RPL_DCP_TEST_022_H_
