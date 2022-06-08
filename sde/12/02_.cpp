
int findKthLargestSTL(vector<int>& nums, int k) {
  if(k>nums.size() || k <=0) return INT_MIN;

  // sort: descending nlogn
  // return k-1 element
  sort(nums.begin(), nums.end(), [](int a, int b) { return a>b; });
  return nums[k-1];
}


int findKthLargestBETTER(vector<int>& nums, int k) {
  if(k>nums.size() || k <=0 || nums.empty()) return INT_MIN;

  auto left = [&] (int idx) {
    // 0 1 2 3 4 5 6
    int child = (idx*2)+1;
    return child< nums.size() ? child : -1;
  };

  auto right = [&] (int idx) {
    // 0 1 2 3 4 5 6
    int child = (idx*2)+2;
    return child< nums.size() ? child : -1;
  };

  auto percolate_down = [&](int idx) {
    // while smaller than left/right child:
    // try to move it as down as possible
    while(true) {
      int L = left(idx);
      int R = right(idx);

      if (L==-1) break;

      // find greater child
      int maxChild = L;
      if (R != -1 && nums[R] > nums[L]) maxChild = R;

      if (nums[idx] < nums[maxChild]) {
        swap(nums[idx], nums[maxChild]);
        idx=maxChild;
      } else break; // already a heap
    }
  };

  auto heapify = [&]() { // MAX HEAP
    for (int i=nums.size()/2; i>=0; i--) {
      percolate_down(i);
    }
  };

  auto pop = [&]() {
    // override first element w/ last one
    // perc down the new top
    int lastIdx = nums.size()-1;
    nums[0]=nums[lastIdx];
    nums.resize(lastIdx);

    percolate_down(0);
  };

  // create a MaxHeap: O(N)
  heapify();

  // 6, 5, 4, 3, 2, 1
  // k=1: 6
  // k=2: 5
  // k=3: 4
  while(--k >0) pop();

  return nums[0];
}

int findKthLargestOPT(vector<int>& nums, int k) {
  priority_queue<int, vector<int>, greater<int>> q;
  for(int i:nums){
    q.push(i);
    if(q.size() > k){
      q.pop();
    }
  }
  return q.top();
}