#ifndef REPL_DCP_INPUT_1_E_H_
#define REPL_DCP_INPUT_1_E_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int k1=7;
vector<int> v1 {};
vector<int> v2 {5};
vector<int> v3 {5};
vector<int> v4 {5, 2};

vector<int> v5 {5, 4, 2};
vector<int> v6 {7, 2, 1};
vector<int> v7 {7, 2, 0};

vector<int> v8 {10, 0, 3};
vector<int> v9 {10, 0, 4, -3};

int k2=-5;
vector<int> v10 {10, 0, -3};
vector<int> v11 {-2, 0, -3};
vector<int> v12 {5, 0, -5};
vector<int> v13 {1, 2, -5};
vector<int> v14 {1, 0, -5};

string res(bool r, bool correct_r) {
  stringstream ss;
  ss << boolalpha << r << ((r==correct_r)?"":" (WRONG)");
  return ss.str();
}

bool sol(vector<int> vec, const int sum);

void test(int k, vector<int> v, std::string sv, bool result) {
  cout << setw(2)<< k << ": "<<sv<<": " << res(sol(v, k), result) << endl;
}

void run_tests() {
  test(k1, v1, " v1", false);
  test(k1, v2, " v2", false);
  test(k1, v3, " v3", false);
  test(k1, v4, " v4", true);
  test(k1, v5, " v5", true);
  test(k1, v6, " v6", false);
  test(k1, v7, " v7", true);
  test(k1, v8, " v8", false);
  test(k1, v9, " v9", true);


  test(k2, v10, "v10", false);
  test(k2, v11, "v11", true);
  test(k2, v12, "v12", true);
  test(k2, v13, "v13", false);
  test(k2, v14, "v14", true);
}

#endif //REPL_DCP_INPUT_1_E_H_
