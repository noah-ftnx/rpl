#include <deque>
using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    const int N = (int) nums.size();
    vector<int> res(N-k+1);
    deque<int> dq;

    for (int i=0; i<N; i++) {

      // front: has bigger elements
      // we have to remove the expired ones

      // remove smaller elements from the back
      // and expired elements
      // remove expired items from the front
      while(!dq.empty() && dq.front() <= i-k) dq.pop_front();


      // remove any smaller elements from the back
      // before adding cur num
      while (!dq.empty() && (nums[dq.back()] <= nums[i])) dq.pop_back();

      dq.push_back(i);

      // 0 1 2 3 4
      if (i-k+1>=0) { // can emit
        res[i-k+1]=nums[dq.front()]; // bigest number
      }
    }

    return res;
  }
};




