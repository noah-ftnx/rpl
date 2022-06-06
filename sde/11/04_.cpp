int search(vector<int>& nums, int target) {
  const int N = (int) nums.size();
  int low=0, high=N-1;

  while (low <= high) {
    int mid = (low+high)/2;

    if (nums[mid]==target) return mid; // found it

    bool visitLeft;
    bool isLeftSorted=nums[low]<=nums[mid];

    if (isLeftSorted) {
      // num is within left sorted range
      if (target>=nums[low] && target<=nums[mid]) visitLeft=true;
      else visitLeft=false;
    } else { // right is sorted (or both)
      // num is within right sorted range
      if (target >= nums[mid] && target <=nums[high]) visitLeft=false;
      else visitLeft=true;
    }

    if (visitLeft) {
      high=mid-1;
    } else {
      low=mid+1;
    }
  }
  return -1;
}
