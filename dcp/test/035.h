#ifndef RPL_DCP_TEST_035_H_
#define RPL_DCP_TEST_035_H_

#include <iostream>
#include <string>
using namespace std;


void test(vector<char>& input, vector<char> correct) {

  for (auto c: input) cout << c << " "; cout << endl;
  partition(input);

  for (auto c: input) cout << c << " ";
  cout << ": " << (input!=correct? " (WRONG)": "correct.") << endl;

}

void run_tests() {
  vector<char> input {'G', 'B', 'R', 'R', 'B', 'R', 'G'};
  vector<char> correct{'R', 'R', 'R', 'G', 'G', 'B', 'B'};
  test(input, correct);
}

#endif  // RPL_DCP_TEST_035_H_
