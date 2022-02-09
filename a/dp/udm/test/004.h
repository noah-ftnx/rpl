#ifndef RPL_A_DP_TEST_004_H_
#define RPL_A_DP_TEST_004_H_

#include <iostream>

// not the full solution. returns only min score
int prototype_score(string text, const int& line_limit);
using fptr_score = decltype(prototype_score);

vector<vector<string>> prototype(string text, const int& line_limit);
using fptr = decltype(prototype);


void test_score_only(string msg, fptr_score function, string input, int line_len, int correct) {
  int score = function(input, line_len);
  cout << msg << ": " << score << (score!=correct? " (WRONG)":"") << endl;
}

void run_tests_score(string msg, fptr_score function) {
  test_score_only(msg, function, "Isabel sat on the step", 10, 36);
}

void test(string msg, fptr function, string input, int line_len, const vector<vector<string>>& correct) {
  vector<vector<string>> result = function(input, line_len);
  cout << endl << msg << ":\n";
  for (auto sentence: result) {
    for (auto word: sentence) cout << word << " ";
    cout << endl;
  }

  cout << endl << (result!=correct? "WRONG.":"Correct") << " (" << msg << ")" << endl;
}

void run_tests(string msg, fptr function) {
  test(msg, function,
       "Isabel sat on the step", 10,
       {
           {"Isabel"},
           {"sat", "on"},
           {"the", "step"}
       });
}

#endif  // RPL_A_DP_TEST_004_H_