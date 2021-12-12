#include "test/test-001.h"

#include <unordered_set>
using namespace std;

bool sol(vector<int> vec, const int sum) {
  if (vec.size() < 2) return false;

  unordered_set<int> r;
  for (auto v: vec) { // O(n)
    if (r.count(v)>0) {
      return true;
    } else {
      r.insert(sum-v); // O(1)
    }
  }
  return false;
}

int main() { run_tests(); return 0; }