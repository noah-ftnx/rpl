#ifndef REPL_DCP_TEST_TEST_001_H_
#define REPL_DCP_TEST_TEST_001_H_

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

vector<int> sol1(vector<int>& vec);
vector<int> sol2(vector<int>& vec);

vector<string> correct_output {
    "120 60 40 30 24 ",
    "2 3 6 ",
    "180 600 360 300 900 ",
};

void print_result(string msg, int input_id, const vector<int>& result) {
  stringstream ss;
  for (auto v: result) ss << v << " ";

  string out = ss.str();

  cout << msg << ":v" << input_id << ": " << out
       << (out.compare(correct_output[input_id-1])!=0?" (WRONG)": "") << endl;
}

void run_tests_trv() {
  vector<int> v1 {1, 2, 3, 4, 5};
  vector<int> v2 {3, 2, 1};
  vector<int> v3 {10, 3, 5, 6, 2};

  vector<int> result;

  cout << "WITH DIVISION:\n";
  result=sol1(v1); print_result("div", 1, result);
  result=sol1(v2); print_result("div", 2, result);
  result=sol1(v3); print_result("div", 3, result);

  cout << "\nWITHOUT DIVISION:\n";
  result=sol2(v1); print_result("no-div", 1, result);
  result=sol2(v2); print_result("no-div", 2, result);
  result=sol2(v3); print_result("no-div", 3, result);
  cout << endl;
}

#endif //REPL_DCP_TEST_TEST_001_H_
