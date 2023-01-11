#include <vector>
using namespace std;

void DNQ(vector<int>& vec, int left, int right) {
  // BASE CASE
  if (left==right) return; // array of size 1 -> already sorted
  
  // DIVIDE
  int mid = left+(right-left)/2;
  DNQ(vec, left, mid);
  DNQ(vec, mid+1, right);
  
  // CONQUER: merge
  int sz=right-left+1;
  vector<int> tmp(sz); int t=0;
  int i,j;
  i=left;
  j=mid+1;
  while (i<=mid && j<=right) {
    if (vec[i]<=vec[j]) {
      tmp[t++]=vec[i++];
    } else {
      tmp[t++]=vec[j++];
    }
  }

  // some elements left on i
  while (i<=mid) tmp[t++]=vec[i++];

  // some elements left on j
  while (j<=right) tmp[t++]=vec[j++];

  // copy from tmp back to orig array
  t=0; i=left;
  while (i<=right) {
    vec[i++]=tmp[t++];
  }
}


void merge_sort(vector<int>& vec) {
  DNQ(vec, 0, vec.size()-1);
}