#include <vector>
using namespace std;

void merge_and_count(vector<int>& vec, int l, int m, int h, int& inv) {
  int i=l, j=m+1, k=0;
  int sz=h-l+1;
  vector<int> merged(sz);
  while (i<=m && j<=h) {
    if (vec[i] < vec[j]) {
      merged[k++]=vec[i++];
    } else {
      merged[k++]=vec[j++];
      // how many positions it will move to the right?
      // size of m array (+1 as it's inclusive)
      // minus the current index
      // alt: it's at the end (m) of left, and will go to the start of right (m+1): 1 movement
      //     i     j
      // 0   1     2   3
      // 3   5     |   4   6
      //     m        m+1
      // 5: will move 1 position
      inv+=(m+1)-i;
    }
  }

  // add remaining ones
  while (i<=m) merged[k++]=vec[i++];
  while (j<=h) merged[k++]=vec[j++];

  // copy merged table
  for (k=0, i=l; i<=h; k++, i++) vec[i]=merged[k];

}

void DNQ(vector<int>& vec, int l, int h, int& inv) {
  if (l < h) {
    int m = (l+h)/2;
    // divide
    DNQ(vec, l, m, inv);
    DNQ(vec, m+1, h, inv);
    // conquer
    merge_and_count(vec, l, m, h, inv);
  }
}

int count_inversions(vector<int> input) {
  int inv {};
  DNQ(input, 0, input.size()-1, inv);
  return inv;
}



#include "test/044.h"
int main() { run_tests(); return 0; }