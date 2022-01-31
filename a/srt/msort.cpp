

#include <vector>
using namespace std;

void merge(vector<int>& vec, int low, int mid, int high) {
  // high is inclusive!
  vector<int> merged(high-low+1);
  int i=low, j=mid+1, k=0;

  while (i<=mid && j<=high) {
    if (vec[i] <= vec[j]) {
      merged[k++]=vec[i++];
    } else {
      merged[k++]=vec[j++];
    }
  }

  // remaining elements
  while (i<=mid) merged[k++]=vec[i++];
  while (j<=high) merged[k++]=vec[j++];

  // copy back the merged vec
  for (k=0, i=low; i<=high; k++, i++) vec[i]=merged[k];
}

// h: high: inclusive
void DNQ(vector<int>& vec, int low, int high) {
  if (low < high) {
    int mid = (low+high)/2;
    // divide
    DNQ(vec, low, mid);
    DNQ(vec, mid+1, high);

    // conquer
    merge(vec, low, mid, high);
  }
}

void merge_sort(vector<int>& vec) {
  DNQ(vec, 0, vec.size()-1);
}


#include "test/msort.h"
int main() { run_tests(); return 0; }

