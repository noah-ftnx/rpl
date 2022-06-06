#include <vector>
#include <climits>
using namespace std;

int Solution::books(vector<int> &A, int B) {
  if (A.empty() || B <=0) return INT_MIN;

  // find binary search range:
  // low: picked just a single element
  // high: picked all elements (imagine having 1 student)
  int low=INT_MAX, high=0;
  for (auto a: A) {
    low=min(low, a);
    high+=a;
  }

  auto isValid = [&](int maxPages) {
    int rs=1; //required students: starting w/ 1 student (TRICKY)
    int pages=0;
    for (auto a: A) {
      // even a single book cannot be handled
      if (a > maxPages) return false;

      if (pages+a > maxPages) {
        // require an extra student
        rs++;
        pages=a; // resetting pages
      } else {
        pages+=a;
      }
      if (rs>B) return false; // require more students that we have
    }
    return true;
  };

  while (low <= high) {
    // try to see if `mid` is a valid solution (B students are enough for it)
    int mid = (low+high)/2;

    if (isValid(mid)) {
      // found a solution, but there might be a better one
      // a better one can have a lower limit => go left
      // res=mid; // NO NEED to keep updating the best answer. low will match it
      high=mid-1;
    } else {
      // invalid solution: we have to increase the limit (mid) => go right
      low=mid+1;
    }
  }
  return low;
}
