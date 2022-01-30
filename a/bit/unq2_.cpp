#include <vector>
using namespace std;

int find_num(vector<int> input) {
  int num{};
  for (auto i: input) num=num xor i;
  return num;
}



#include "test/unq2.h"
int main() { run_tests(); return 0; }
