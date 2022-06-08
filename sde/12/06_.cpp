#include <unordered_map>
#include <vector>
using namespace std;

class SolutionBF {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;

    for (auto num: nums) {
      int cnt=1;
      if (mp.count(num) >0) {
        cnt=mp[num]+1;
      }
      mp[num]=cnt;
    }

    vector<pair<int, int>> tmp;
    for (auto kv: mp) tmp.push_back({kv.first, kv.second});
    // sort based on count, ascending (results on the back)
    sort(tmp.begin(), tmp.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });

    vector<int> res;
    while (res.size() < k && !tmp.empty()) {
      res.push_back(tmp.back().first);
      tmp.pop_back();
    }
    return res;
  }
};




#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp; // kv: num, freq

    // still have to create the freq histogram
    for (auto num: nums) {
      int cnt=1;
      if (mp.count(num) >0) {
        cnt=mp[num]+1;
      }
      mp[num]=cnt;
    }

    // can save some time:
    // pair: freq, num
    priority_queue<pair<int,int>> pq; // MaxHeap on freq (first)


    vector<int> res;
    int consideredElements=0;
    // for each element
    for (auto kv: mp) {
      pq.push({kv.second, kv.first});
      // k=3
      //       x x x
      // 1 2 3 4 5 6 : SZ:6 k=3 GT? means pq size 4+!
      if (pq.size() > mp.size()-k) {
        // found first answer (on cur iteration)
        // might not be the most frequent one, but we don't care about the order
        res.push_back(pq.top().second); pq.pop();
        if (res.size() == k) break;
      }
    }

    return res;
  }
};


