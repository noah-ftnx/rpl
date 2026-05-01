#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>
#include <map>
#include <functional>
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

        // build result in correct order
        vector<int> result;
        for (int query: queries) {
            result.push_back(result_mp[query]);
        }

        return result;
    }
};

#include ".inc/check.h"

void run_test(vector<int> nums, vector<int> queries, vector<int> correct) {
    Solution s;
    auto result = s.answerQueries(nums, queries);
    check_result("answerQueries", result, correct);
}

int main() {
    run_test({4, 5, 2, 1}, {3, 10, 21}, {2, 3, 4});
    run_test({2, 3, 4, 5}, {1}, {0});
    return 0;
}
