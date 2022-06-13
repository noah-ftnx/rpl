class SolutionBF {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    /**
      0 1 2 (i) N
      3 2 1
      2 3 4 1 5 6
      0 1 2 3 4 5 (j) M

  res: size N of NGElements

  next greater:
  - not the biggest. just next greatest
            */
    const int N = (int) nums1.size();
    const int M = (int) nums2.size();

    for (int i=0; i<N; i++) {
      int num = nums1[i];

      int ge=-1;
      for (int j=M-1; j>=0; j--) {
        if (nums2[j]==num) break; // found the (distinct num)
        if (nums2[j] > num) ge=nums2[j];
      }
      nums1[i]=ge;
    }
    return nums1;
  }
};


#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class SolutionOPT {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    const int N = (int) nums1.size();
    const int M = (int) nums2.size();
    stack<int> q;

    unordered_map<int, int> mp; // <num, idx>
    for (int i=0; i<N; i++) { mp[nums1[i]]=i; }

    int filled=0;
    for (int j=M-1; j>=0; j--) {
      // drop everything that is smaller than cur num
      // if it's the largest num (so far) its OK:
      // the queue has nothing of use
      // also, any prev elements will not be utilizing a smaller num
      while (!q.empty() && q.top() <= nums2[j]) q.pop();

      if (mp.count(nums2[j])) {
        int ge=-1;
        if (!q.empty()) { ge=q.top(); }
        nums1[mp[nums2[j]]]=ge;
        if(++filled==N) break;
      }

      q.push(nums2[j]);
    }
    return nums1;
  }
};