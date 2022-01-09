#ifndef RPL_DCP_TEST_018_BONUS_H_
#define RPL_DCP_TEST_018_BONUS_H_

#include <iostream>

bool _wrong = false;
void test(int N, bool print, vector<vector<int>> correct) {
  auto solutions = n_queensBT(N);
  cout << N << " Queens. Solutions: " << solutions.size() << endl;

  // for (auto solution: solutions) {
  //   cout << "{ ";
  //   for  (auto i: solution) cout << i << ", ";
  //   cout << "},\n";
  // }

  if (print) {
    for (int i=0; i<solutions.size(); i++) {
      auto solution = solutions[i];
      cout << "Solution " << (i+1) << ":" << endl;
      for (int r=0; r<solution.size(); r++) {
        int c = solution[r];
        for (int k=0; k<N; k++) {
          if (k == c) cout << " Q";
          else cout << " .";
        }
        cout << endl;

      }
      cout << endl;
    }
  } else {
    cout << "(printing for N "<<N<<" skipped)\n";
  }

  if (correct != solutions) {
    _wrong=true;
    cout << " WRONG.";
  }
}

void run_tests() {
  test(4, true, {{1,3,0,2}, {2,0,3,1}});
  test(5, false,
       {
           { 0, 2, 4, 1, 3, },
           { 0, 3, 1, 4, 2, },
           { 1, 3, 0, 2, 4, },
           { 1, 4, 2, 0, 3, },
           { 2, 0, 3, 1, 4, },
           { 2, 4, 1, 3, 0, },
           { 3, 0, 2, 4, 1, },
           { 3, 1, 4, 2, 0, },
           { 4, 1, 3, 0, 2, },
           { 4, 2, 0, 3, 1, }
       });


  if (_wrong) {
    cout << "\n\nWrong results found.\n";
  }
}

#endif  // RPL_DCP_TEST_018_BONUS_H_
