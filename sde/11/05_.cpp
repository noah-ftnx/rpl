double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  const int N = (int) nums1.size();
  const int M = (int) nums2.size();
  const int size = N + M;
  const int leftSize = ((size+1)/2);

  // do binary search for the smaller array
  // OTHERWISE IT WILL FAIL!
  if (M < N) {
    return findMedianSortedArrays(nums2, nums1);
  }

  // must pick elements for the left subarray, max of that size
  // why not N-1? because this is the cut! so N means ALL the elements
  int low=0, high=N;
  while (low <= high) {
    int cut1 = (low+high)/2;

    // whatever is before the cut1 is l1 (left portion from 1st arr)
    // whatever after cut1 is r1 (right portion from 1st arr)

    int l1 = cut1==0? INT_MIN: nums1[cut1-1]; // might be zero elements
    int r1 = cut1==N? INT_MAX: nums1[cut1];

    // must take the remaining elements from r2
    // Assuming taken 2 elements from r1
    // 0 1 2 3 (cut1 at idx 2: [0,1] elements)
    int cut2=leftSize-cut1;
    int l2 = cut2==0? INT_MIN: nums2[cut2-1];
    int r2 = cut2==M? INT_MAX: nums2[cut2];

    bool validCut1 = l1 <= r2;
    bool validCut2 = l2 <= r1;


    if (validCut1 && validCut2) { // found answer
      bool oddSize = size%2==1;
      if (oddSize) {
        return max(l1, l2);
      } else {
        return (max(l1, l2) + min(r1, r2)) /2.0;
      }
    } else if (!validCut1) {
      // must decrease l1 (has more elements than it should)
      // meaning: cut1 goes to left
      high=cut1-1;

    } else { // !validCut2: has more elements than it should
      // must decrease l2 (or increase l1)
      // meaning: cut1 goes to right
      low=cut1+1;
    }
  }

  return -1;
}