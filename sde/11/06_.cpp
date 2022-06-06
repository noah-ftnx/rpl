#include <climits>
#include <iostream>
using namespace std;

int kthElementBUG(int arr1[], int arr2[], int n, int m, int k) {

  /*
   2, 3, 6, 7, 9
   1, 4, 8, 10
  */

  k--; // zero-based index

  if (n<=0 && m<=0) return -1; // empty arrays
  else if (k>=n+m) return -1; // out of bounds

  // one of the array is empty
  if (n==0) return arr2[k];
  else if (m==0) return arr1[k];

  // find small and large arrays
  int *sm = arr1, *lg=arr2, szSm=n, szLg=m; // assumption
  if (arr2[0] < arr1[0]) {
    sm=arr2;
    lg=arr1;
    szSm=m;
    szLg=n;
  }

  int i,j,idx; // not included anything yet
  i=j=idx=-1; // i points to sm, j to lg, and idx on a sorted array
  while (idx < k) {
    i++;
    idx++;

    // 1 2 3 4 5 9
    // 2 2 2 2 2

    // sm consumed or sm no longer smaller (given that j is not consumed)
    const bool smConsumed = i==szSm; // just went past it's last valid position
    const bool lgNotConsumedAndSmaller = j+1 < szLg && (lg[j+1] < sm[i]);
    if (smConsumed || lgNotConsumedAndSmaller) { // it is not
      // swap lg and sm
      swap(sm, lg);
      swap(szSm, szLg);
      swap(i, j);
    }
  }
  return sm[i];
}


// { Driver Code Starts

// } Driver Code Ends
class Solution{
 public:

  // arr1 is the smallest array
  int solve(int arr1[], int arr2[], int n, int m, int k) {
    // decide how to split on arr1
    // might take too few items from arr1, and even if we take the whole of arr2,
    // we can still not have k elements
    // 0 or k-m: if positive: we need at least that from arr1
    // if negative? we can take 0 elements from arr1
    int low=max(0, k-m);
    int high = min(k, n);

    while (low <= high) {
      int slice1 = (low+high)/2;
      int slice2 = k-slice1;

      cout << "s1: " << slice1 << endl;
      cout << "s2: " << slice2 << endl;

      int l1 = slice1==0? INT_MIN : arr1[slice1-1];
      int l2 = slice2==0? INT_MIN : arr2[slice2-1];

      int r1 = slice1==n? INT_MAX : arr1[slice1];
      int r2 = slice2==m? INT_MAX : arr2[slice2];

      cout << "l1 <= r2 | " << l1 << " <= " << r2 << endl;
      cout << "l2 <= r1 | " << l2 << " <= " << r1 << endl;


      bool validSlice1 = l1 <= r2;
      bool validSlice2 = l2 <= r1;

      if (validSlice1 && validSlice2) {
        return max(l1, l2); // kth element
      } else if (!validSlice1) {
        cout << "go left\n";
        // something in l1 is bigger than r2
        // we have to decrease l1 => go left
        high=slice1-1;
      } else { // something in l2 is bigger than r2
        // we have to decrase l2.
        // alt: this means increasing l1 => go right
        cout << "go right\n";
        low=slice1+1;
      }
    }

    return INT_MIN;

  }

  int kthElement(int arr1[], int arr2[], int n, int m, int k)
  {

    if (n<=0 && m<=0) return INT_MIN;
    if (k > n+m) return INT_MIN;


    // CHECK if one is empty?
    if (n<=m) return solve(arr1, arr2, n, m, k);
    else return solve(arr2, arr1, m, n, k);
  }
};

// { Driver Code Starts.

// Driver code
int main()
{
    int n=7,m=11,k=15;
  int arr1[] = {1, 10, 10, 25, 40, 54, 79},
      arr2[]= {15, 24, 27, 32, 33, 39, 48, 68, 82, 88, 90};

    Solution ob;
    cout << ob.kthElement(arr1, arr2, n, m, k) << endl;
  return 0;
}  // } Driver Code Ends