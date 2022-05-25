#include <vector>
using namespace std;

int mergeSort(vector<int> &arr, int l, int r) {
  int mid = (l+r)/2;
  int inv {};

  if (l<r) {
    inv+=mergeSort(arr, l, mid);
    inv+=mergeSort(arr, mid+1, r);

    // conquer: merge arrays and count inv
    const int sz = r-l+1;
    vector<int> tmp(sz);
    int k {};
    int i=l, j=mid+1;
    while (i<=mid && j<=r) {
      if (arr[i]<arr[j]) { // not an inversion
        tmp[k++]=arr[i++];
      } else { // some inversions
        //   i m   m+1 must move 3:
        // 1 5 6 |  4  8 9
        inv+=mid+1-i;
        tmp[k++]=arr[j++];
      }
    }

    // add remaining elements
    while (i<=mid) { tmp[k++]=arr[i++]; }
    while (j<=r) { tmp[k++]=arr[j++]; }

    // write back results
    k=0;
    while(l<=r) { arr[l++]=tmp[k++]; }
  }

  return inv;
}

long long getInversions2(vector<int> arr, int n) {
  return mergeSort(arr, 0, n-1);
}


long long getInversions(vector<int> arr, int n) {
  int sum{};
  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      // pairs where j is always greater
      if (arr[i]>arr[j]) sum++;
    }
  }
  return sum;
}


#include "test/06.h"
int main() {
  run_tests("Sol", getInversions);
  run_tests("Opt", getInversions2);

  print_report();
  return 0;
}