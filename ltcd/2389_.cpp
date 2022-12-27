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


        // dont sort queries
        // instead compute prefix sum
        //     assume: 1,  2,  3,   5
        // prefix_sum: 1,  3,  6,  11
        struct
                vector<int> prefix_sum;
        int sum=0;
        for (int num: nums) {
            sum+=num;
            prefix_sum.push_back(sum);
        }

        int cnt=0, num_idx=0; sum=0;
        vector<int> result;
        for (int query: queries) {
            // binary search:
            // find point in array where: it is greater than cur index
            auto iterator=upper_bound(prefix_sum.begin(), prefix_sum.end(), query);

            // find index:
            // example: query=3: must return 3 for:
            // 1, 2, 3, 5
            // iterator will be at 5 (idx3, zero based)
            int idx = iterator-prefix_sum.begin();
            result.push_back(idx);
        }

        return result;
    }
};
