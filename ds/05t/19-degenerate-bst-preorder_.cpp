#include <optional>
#include <vector>
using namespace std;

// Given preorder traversal of a BST with distinct values.
// Return true if the BST is degenerate.
bool is_degenerate(const vector<int> &preorder) {
  optional<int> lo {};
  optional<int> hi {};

  for (int i = 1; i < (int) preorder.size(); i++) {
    int cur = preorder[i];
    int prev = preorder[i - 1];

    if (lo && cur <= *lo) return false;
    if (hi && cur >= *hi) return false;

    if (cur < prev) {
      hi = prev;
    } else if (cur > prev) {
      lo = prev;
    } else {
      return false; // duplicate
    }
  }

  return true;
}

#include "test/19-degenerate-bst-preorder.h"
int main() { run_tests(); return 0; }
