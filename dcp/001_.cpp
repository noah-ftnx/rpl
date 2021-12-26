#include <unordered_set>
#include <vector>
using namespace std;

bool sol(vector<int> vec, const int sum) {
  if (vec.size() < 2) return false;

  unordered_set<int> r;
  for (auto v: vec) { // O(n)
    if (r.contains(v)) {
      return true;
    } else {
      r.insert(sum-v); // O(1)
    }
  }
  return false;
}

#include "test/001.h"
int main() { run_tests(); return 0; }