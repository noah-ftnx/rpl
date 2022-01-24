#ifndef RPL_DCP_TEST_028_H_
#define RPL_DCP_TEST_028_H_

#include <iostream>

bool _wrong {};
void test(vector<string> input, int k, const vector<string>& correct) {
  auto result = justify(input, k);
  for (string line: result) cout << line << endl;
  bool wrong = correct!=result;
  _wrong|=wrong;
  cout << (wrong? "WRONG.":"Correct.") << endl;
}

void run_tests() {
  test({"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"}, 16,
       {"the  quick brown",
        "fox  jumps  over",
        "the   lazy   dog" });

  test({"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog", "OMG"}, 16,
       {"the  quick brown",
        "fox  jumps  over",
        "the lazy dog OMG",
         });

  test({"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog", "OMG", "ABC"}, 16,
       {"the  quick brown",
        "fox  jumps  over",
        "the lazy dog OMG",
        "ABC             ",
       });

  test({"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog", "OMG", "ABC", "123"}, 16,
       {"the  quick brown",
           "fox  jumps  over",
           "the lazy dog OMG",
           "ABC          123",
       });

      cout << endl << (_wrong? "WRONG RESULTS.": "Correct (all).") << endl;
}

#endif  // RPL_DCP_TEST_028_H_
