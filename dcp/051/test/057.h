#ifndef RPL_DCP_051_TEST_057_H_
#define RPL_DCP_051_TEST_057_H_

#include <iostream>
#include <iomanip>

bool _wrong {};
void test(string input, int k, const vector<string>& correct) {
  auto result = break_string(input, k);
  for (string line: result) cout << line << endl;
  bool wrong = correct!=result;
  _wrong|=wrong;
  cout << (wrong? "WRONG.":"Correct.") << endl << endl;
}

void run_tests() {
  test({"the quick brown fox jumps over the lazy dog"}, 16,
       {"the quick brown",
        "fox jumps over",
        "the lazy dog" });

  test({"the quick brown fox jumps over the lazy dog OMG"}, 16,
       {"the quick brown",
           "fox jumps over",
           "the lazy dog OMG",
       });

  test({"the quick brown fox jumps over the lazy dog OMG ABC"}, 16,
       {"the quick brown",
           "fox jumps over",
           "the lazy dog OMG",
           "ABC",
       });

  test({"the quick brown fox jumps over the lazy dog OMG ABC 123"}, 16,
       {"the quick brown",
           "fox jumps over",
           "the lazy dog OMG",
           "ABC 123",
       });

  cout << endl << (_wrong? "WRONG RESULTS.": "Correct (all).") << endl;
}

#endif  // RPL_DCP_051_TEST_057_H_