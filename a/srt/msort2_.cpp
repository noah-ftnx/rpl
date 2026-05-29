#include <vector>
using namespace std;

void merge_sort(vector<int>& vec) {
  const int n = vec.size();
  if (n < 2) return;

  vector<int> tmp(n);
  for (int width = 1; width < n; width <<= 1) {
    for (int l = 0; l < n; l += 2 * width) {
      int m = l + width - 1;
      if (m >= n - 1) continue;
      int h = l + 2 * width - 1;
      if (h >= n) h = n - 1;

      int i = l;
      int j = m + 1;
      int k = l;
      while (i <= m && j <= h) {
        if (vec[i] <= vec[j]) {
          tmp[k++] = vec[i++];
        } else {
          tmp[k++] = vec[j++];
        }
      }
      while (i <= m) tmp[k++] = vec[i++];
      while (j <= h) tmp[k++] = vec[j++];
      for (int p = l; p <= h; ++p) vec[p] = tmp[p];
    }
  }
}

#include "test/msort2.h"
int main() { run_tests(); return 0; }
