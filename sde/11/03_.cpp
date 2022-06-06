int singleNonDuplicate(vector<int>& nums) {
  const int N = (int) nums.size();
  // covers nums of size 1
  int low=0, high=N-2; // because we end when we cross high

  while (low<=high) {
    int mid = (low+high)/2;

    // 0 1 2 3 4 5 6
    // 1 1 2 3 3 4 4
    bool isOdd = (mid%2)==1;
    bool isEven=!isOdd;

    bool isOK =
        // when it's odd: it has to be the 2nd of 2 nums
        (isOdd && (mid>0 && nums[mid-1]==nums[mid])) ||
            // when its even: 1st of 2 nums
            (isEven && (nums[mid]==nums[mid+1]));

    // mid^1:
    // - odd: compare with prev evenwork st
    // - even -> compare with next odd
    // bool isOK = nums[mid]==nums[mid^1];

    if (isOK) { // no missing number
      // go t o right
      low=mid+1;
    } else {
      high=mid-1;
    }
  }
  return nums[low];
}