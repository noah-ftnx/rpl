#include <any>
#include <vector>
using namespace std;

int productSum(vector<any> array, int depth = 1) {
  int sum = 0;
  for (auto el: array) {
    if (el.type() == typeid(int)) {
      sum += any_cast<int>(el);
    } else if (el.type() == typeid(vector<any>)) {
      sum += productSum(any_cast<vector<any>>(el), depth + 1);
    }
  }
  return sum * depth;
}

#include "test/05-product-sum.h"
int main() { run_tests(); return 0; }
