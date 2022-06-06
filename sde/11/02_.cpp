#include <climits>
#include <vector>
using namespace std;

int numsGE(const vector<int> &row, int k) {
  // return 4:
  //         . (next GT el)
  // 0 1 2 3 4 5 6
  // 1 2 3 3 6 7 9
  //     l/m h
  //       h
  //         l
  int low=0, high= (int) row.size()-1;

  while (low <= high) {
    int mid = (low+high)/2;
    if (row[mid] <=k) {
      // the solution (upper bound) is on the right
      low=mid+1;
    } else { // el is GT
      // it might be a solution, or it might not be
      // if it is, then in next 2 iterations low will have our answer
      high=mid-1;
    }
  }

  return low; // happens to conveniently carry the size
               // 0-based indexing, and we stop right after the last element that we are counting
}

int getMedian(vector<vector<int>> &matrix) {

  if (matrix.empty() || matrix[0].empty()) return INT_MIN;
  const int N = (int) matrix.size();
  const int M = (int) matrix[0].size();
  const int TOTAL=N*M; // odd

  /*
  1 3 7
  2 5 6
  3 4 9

  1 2 3 3 (4) 5 6 7 9
  1 .. 9
  */

  int low=1, high=INT_MAX; // 2^32

  while (low <= high) {
    int mid = (low+high)/2;
    int sum=0;
    for (auto row=0; row<N; row++) {
      sum+=numsGE(matrix[row], mid);
    }

    // 1 2 3 3 (4) 5 6 7 9
    // nums=9
    // 9/2=4

    if (sum <= TOTAL/2) {
      // we need more numbers in the sum
      // go to right
      low=mid+1;
    } else {
      // more numbers than mid (in odd TOTAL)
      // might be the answer or not
      // if it is, it will cause the pointers to cross
      // leaving answer in low
      high=mid-1;
    }
  }
  return low;
}