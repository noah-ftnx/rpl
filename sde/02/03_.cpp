#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  int i,j,e;
  i=m-1, j=n-1;
  e=m+n-1; // last position to override

  while (i>=0 && j>=0) {
    if (nums1[i] > nums2[j]) {
      nums1[e--]=nums1[i--];
    } else {
      nums1[e--]=nums2[j--];
    }
  }

  // when i is done: copy remaining j elements
  while (j>=0) {
    nums1[e--]=nums2[j--];
  }

  // when j is done: i is done
}


#include "test/03.h"
int main() {
  run_tests("Sol", merge);

  print_report();
  return 0;
}

