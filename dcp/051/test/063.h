#ifndef RPL_DCP_051_TEST_063_H_
#define RPL_DCP_051_TEST_063_H_

#include <iostream>
#include <iomanip>

bool _wrong {};

void test(vector<vector<char>> input, string word, bool correct) {
  bool result = word_exists(input, word);
  bool wrong = result!=correct;
  _wrong|=wrong;
  cout << word << " exists: " << boolalpha << result
       << (wrong? " (WRONG)": "") << endl;
}

void print_report() {
  cout << endl <<  (_wrong? "WRONG RESULTS." : "Correct (all tests)") << endl;
}

void run_tests() {
  test({{'F', 'A', 'C', 'I'},
           {'O', 'B', 'Q', 'P'},
           {'A', 'N', 'O', 'B'},
           {'M', 'A', 'S', 'S'}
       }, "FOAM", true);

  test({{'F', 'A', 'C', 'I'},
        {'O', 'B', 'Q', 'P'},
        {'A', 'N', 'O', 'B'},
        {'M', 'A', 'S', 'S'}
       }, "MASS", true);


  test({{'F', 'A', 'C', 'I'},
        {'O', 'B', 'Q', 'P'},
        {'A', 'N', 'O', 'B'},
        {'M', 'A', 'S', 'S'}
       }, "NOB", true);

  test({{'F', 'A', 'C', 'I'},
        {'O', 'B', 'Q', 'P'},
        {'A', 'N', 'O', 'B'},
        {'M', 'A', 'S', 'S'}
       }, "FOAX", false);

  test({{'F', 'A', 'C', 'I'},
        {'O', 'B', 'Q', 'P'},
        {'A', 'N', 'O', 'B'},
        {'M', 'A', 'S', 'S'}
       }, "ABC", false);

  test({{'F', 'A', 'C', 'I'},
        {'O', 'B', 'Q', 'P'},
        {'A', 'N', 'O', 'B'},
        {'M', 'A', 'S', 'S'}
       }, "FOAMM", false);


  print_report();
}

#endif  // RPL_DCP_051_TEST_063_H_