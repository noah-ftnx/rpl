/*
 *
IDEA:
nums: n
queries: m

vector<answer>: size m
- ans[i]: max size of subsequence from nums -> sum <=queries[i]

nums: 4, 5, 2, 1
quer: 4, 10, 21

nums: 4,5
query: 10

1. sort nums & take sum
sum: 12
1, 2, 3, 4 (sort asc)

2. for each q: queries (slower: N*M)
int cnt, sum
for each num:
    update sum, cnt
    as long as <= q
append result


2.opt sort queries, ascending N+M CAUSES ISSUES ... on computing result

int cnt, sum = 0
num_idx
for each q: queries:
  for each num: (remeber num_idx)
    update cnt, sum
    as long as <= q
append result
*/


#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        const int N = nums.size();
        const int M = queries.size();
        if (N==0) return {};
        if (M==0) return {};

        sort(nums.begin(), nums.end(), less<int>());
        vector<int> queries_sorted=queries;
        sort(queries_sorted.begin(), queries_sorted.end(), less<int>());

        int cnt=0, sum=0, num_idx=0;
        // must preserve the original order (of queries)
        unordered_map<int, int> result_mp;

        for (int query: queries_sorted) {
            for (; num_idx<N; num_idx++) {
                int num = nums[num_idx];
                // exceeded limits
                if (sum+num > query) break;

                sum+=num;
                cnt++;
            }

            result_mp.insert(make_pair(query, cnt));
        }

        vector<int> result;
        for (int query: queries) {
            result.push_back(result_mp[query]);
        }

        return result;
    }
};