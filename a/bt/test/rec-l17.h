#ifndef INC_070__CPP_A_BT_TEST_REC_L17_H_
#define INC_070__CPP_A_BT_TEST_REC_L17_H_

#include <iostream>

bool _wrong = false;

void test(string input, vector<vector<string>> correct) {
  cout << "Input: " << input << endl;

  auto result = partition(input);
  cout << "Result:\n";
  for (auto vec : result) {
    for (string i : vec) cout << i << " "; cout << endl;
  }

  bool wrong = result!=correct;
  _wrong|=wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ") << endl << endl;
}

void run_tests() {

  test("abc", { {"a", "b", "c"}});
  test("abb", { {"a", "b", "b"},
       {"a", "bb"}});

  test("aabb", { {"a", "a", "b", "b"},
                 {"a","a", "bb"},
                 {"aa", "b","b"},
                 {"aa", "bb"},
               });

  if (_wrong) {
    cout << "[FAIL]\n";
  } else {
    cout << "[PASS]: ALL results.\n";
  }
}


#endif  // INC_070__CPP_A_BT_TEST_REC_L17_H_