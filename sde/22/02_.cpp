#include <vector>
#include <unordered_map>
using namespace std;

vector<int> Solution::dNums(vector<int> &A, int B) {
  unordered_map<int, int> mp;
  queue<int> q;

  vector<int> res;

  for (int i=0; i< (int) A.size(); i++) {
    int num = A[i];

    if (q.size() >= B) {
      int pnum = q.front(); q.pop(); // popped num
      mp[pnum]--;
      if (mp[pnum]==0) mp.erase(pnum);
    }

    int cnt = 0;
    if (mp.count(num) >0) cnt=mp[num];
    q.push(num);
    mp[num]=++cnt;

    bool canEmit=i>=B-1;
    if (canEmit) res.push_back((int) mp.size());
  }

  return res;
}
