#include <vector>
using namespace std;

void merge_lists(vector<int>& vec, int l, int m, int h) {
  vector<int> C(h-l+1);
  int i=l, j=m+1, k=0;
  while (i <=m && j <=h) {
    if (vec[i] < vec[j]) {
      C[k++]=vec[i++];
    } else {
      C[k++]=vec[j++];
    }
  }
  // copy remaining elements
  while (i<=m) C[k++]=vec[i++];
  while (j<=h) C[k++]=vec[j++];
  // store back to array
  for (k=0, i = l; i<=h; i++, k++) vec[i] = C[k];
}

void DNQ(vector<int>& vec, int l, int h) {
  if (l < h) {
    int mid = (l + h) / 2;
    DNQ(vec, l, mid);     // left subarray
    DNQ(vec, mid + 1, h); // right subarray
    merge_lists(vec, l, mid, h);
  }
}

void merge_sort(vector<int>& vec) {
  DNQ(vec, 0, vec.size()-1);
}


#include "test/msort.h"
int main() { run_tests(); return 0; }

