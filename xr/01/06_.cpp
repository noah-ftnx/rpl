#include <vector>
using namespace std;


void BF(int i, int limit, int target, vector<vector<int>> &res,  vector<int> &cur, vector<int> vec) {
  const int N = vec.size();
  if (target==0 && limit==0) { // found a solution
    res.push_back(cur);
    return;
  }
  // negative numbers: we might reach target at 2nd number,
  // and then the 3rd one is a zero.
  // so reaching a target before reaching limit should be ignored.
  //
  // we used all numbers (limit zero), or we ran out of input
  else if (limit==0 || i==N) return;

  // pick
  cur.push_back(vec[i]);
  BF(i+1, limit-1, target-vec[i], res, cur, vec);
  cur.pop_back();

  // skip
  BF(i+1, limit, target, res, cur, vec);
}

vector<vector<int>> tnsBF(vector<int> vec, int target) { // backtracking
  sort(vec.begin(), vec.end());
  vector<vector<int>> res; vector<int> cur;
  BF(0, 3, target, res, cur, vec);
  return res;
}



vector<vector<int>> tnsBF2(vector<int> vec, int target) {
  const int N = vec.size();
  sort (vec.begin(), vec.end());
  vector<vector<int>> res;
  int sum {};
  for (int i=0; i<N; i++) {
    sum=vec[i];
    for (int j=i+1; j<N; j++) {
      sum+=vec[j];
      for (int k=j+1; k<N; k++) {
        sum+=vec[k];
        if (sum==target) res.push_back({vec[i], vec[j], vec[k]});
        sum-=vec[k];
      }
      sum-=vec[j];
    }
  }
  return res;
}



vector<vector<int>> tnsOPT(vector<int> vec, int target) {
  const int N = vec.size();
  vector<vector<int>> res;
  sort(vec.begin(), vec.end());
	
  // pick first num
  for (int i=0; i<N; i++) {
    // pick last 2 nums:
    int left=i+1, right=N-1;
		
    while (left < right) {
      int sum=vec[i]+vec[left]+vec[right];
      if (sum==target) { // solved
        // found a solution
        res.push_back({vec[i], vec[left], vec[right]});
        // we might have more solutions:
        right--; left++;
      } else if (sum > target) { // need a smaller num
        right--;
      } else { // need greater num
        left++;
      }
    }
  }
  return res;
}

// TODO