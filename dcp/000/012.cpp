// INCLUDES

int count_bf(int N, vector<int> steps);

int count_td(int N, vector<int> steps);

int count_bu(int N, vector<int> steps);

int sol(int N, vector<int> steps);


//////////////////////////////////////////////////////



#include "test/012.h"
int main() {
  test_function("BF", count_bf);
  test_function("TD", count_td);
  test_function("BU", count_bu);
  test_function("sol", sol);

  if (_wrong) { cout << "ERRORS FOUND.\n"; }

  return 0;
}