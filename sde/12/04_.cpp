class MedianFinder {
 public:
  vector<int> nums;
  MedianFinder() { }

  void addNum(int num) {
    nums.push_back(num);
    sort(nums.begin(), nums.end()); // nlogn
  }

  double findMedian() {
    if (nums.size()%2==1) { // odd
      // 0 1 2 3 4
      // 1 2 3 4 5
      return nums[nums.size()/2]; // zero-based index
    } else {
      // 0 1
      // 1 2
      // 0 1 2 3
      // 1 2 3 4
      return (nums[nums.size()/2]+nums[-1+nums.size()/2])/2.0;
    }
  }
};


class MedianFinderOPT {
 public:

  priority_queue<int, vector<int>, greater<int>> mnq;
  priority_queue<int, vector<int>, less<int>> mxq;

  MedianFinder() {
  }

  void addNum(int num) {
    // add anyway to mnq: (right group, bigger nums)
    mnq.push(num);

    int sz = mnq.size() + mxq.size();
    // accessing top: 1st time: will be odd
    // 2nd time: both will have an item
    if (sz%2==1) { // odd rule: move from mnq to topq
      int mn = mnq.top(); mnq.pop();
      mxq.push(mn);
    } else if (mnq.top() < mxq.top()) { // mess-up rule
      // swap tops
      int mn = mnq.top(); mnq.pop();
      int mx = mxq.top(); mxq.pop();
      mnq.push(mx);
      mxq.push(mn);
    }
  }

  double findMedian() {
    int sz = mxq.size() + mnq.size();
    if (sz%2==1) { // odd
      return mxq.top();
    } else return (mxq.top() + mnq.top())/2.0;
  }
};