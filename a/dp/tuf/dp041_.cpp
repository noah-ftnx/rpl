#include <vector>
using namespace std;

int BF(int idx, int last_idx, vector<int>& nums) {
    const int N = (int) nums.size();
    // base case considered all numbers
    if (idx==0) return 0;

    // first num or num smaller than last pick
    bool can_pick = last_idx==N+1 || nums[idx-1]<nums[last_idx-1];
    if (can_pick) {
        int pick=1+BF(idx-1, idx, nums);
        int skip=BF(idx-1, last_idx, nums);
        return max(pick, skip);
    } else { // must skip
        return BF(idx-1, last_idx, nums);
    }
}

int lengthOfLISBF(vector<int>& nums) {
    const int N = (int) nums.size();
    return BF(N, N+1, nums);
}



int MMZ(int idx, int last_idx, vector<int>& nums, vector<vector<int>> &dp) {
    const int N = (int) nums.size();
    // base case considered all numbers
    if (idx==0) return 0;

    if (dp[idx][last_idx]!=-1) return dp[idx][last_idx];

    // first num or num smaller than last pick
    bool can_pick = last_idx==N+1 || nums[idx-1]<nums[last_idx-1];
    if (can_pick) {
        int pick=1+MMZ(idx-1, idx, nums, dp);
        int skip=MMZ(idx-1, last_idx, nums, dp);
        return dp[idx][last_idx]=max(pick, skip);
    } else { // must skip
        return dp[idx][last_idx]=MMZ(idx-1, last_idx, nums, dp);
    }
}

int lengthOfLISMMZ(vector<int>& nums) {
    const int N = (int) nums.size();
    vector<vector<int>> dp (N+1, vector<int>(N+2, -1));
    return MMZ(N, N+1, nums, dp);
}



int lengthOfLISBU(vector<int>& nums) {
    const int N = (int) nums.size();
    vector<vector<int>> dp (N+1, vector<int>(N+2, 0));

    // base case considered all numbers
    // dp[0][last_idx]=0 (covered by dp init)

    for (int idx=1; idx<=N; idx++) {
        for (int last_idx=0;  last_idx<=N+1; last_idx++) {
            // first num or num smaller than last pick
            bool can_pick = last_idx==N+1 || nums[idx-1]<nums[last_idx-1];
            if (can_pick) {
                int pick=1+dp[idx-1][idx];
                int skip=dp[idx-1][last_idx];
                dp[idx][last_idx]=max(pick, skip);
            } else { // must skip
                dp[idx][last_idx]=dp[idx-1][last_idx];
            }
        }
    }
    return dp[N][N+1];
}



int lengthOfLISOPT(vector<int>& nums) {
    const int N = (int) nums.size();
    vector<int> prev, cur(N+2, 0);

    // base case considered all numbers
    // dp[0][last_idx]=0 (covered by dp init)

    for (int idx=1; idx<=N; idx++) {
        prev=cur;
        for (int last_idx=0;  last_idx<=N+1; last_idx++) {
            // first num or num smaller than last pick
            bool can_pick = last_idx==N+1 || nums[idx-1]<nums[last_idx-1];
            if (can_pick) {
                int pick=1+prev[idx];
                int skip=prev[last_idx];
                cur[last_idx]=max(pick, skip);
            } else { // must skip
                cur[last_idx]=prev[last_idx];
            }
        }
    }
    return cur[N+1];
}



int lengthOfLISOPT2(vector<int>& nums) {
    const int N = (int) nums.size();
    vector<int> row(N+2, 0);

    // base case considered all numbers
    // dp[0][last_idx]=0 (covered by dp init)

    for (int idx=1; idx<=N; idx++) {
        for (int last_idx=0;  last_idx<=N+1; last_idx++) {
            // first num or num smaller than last pick
            bool can_pick = last_idx==N+1 || nums[idx-1]<nums[last_idx-1];
            if (can_pick) {
                int pick=1+row[idx];
                int skip=row[last_idx];
                row[last_idx]=max(pick, skip);
            }
        }
    }
    return row[N+1];
}



#include "test/dp041.h"
int main() {
    run_tests("BF", lengthOfLISBF);
    run_tests("MMZ", lengthOfLISMMZ);
    run_tests("BU", lengthOfLISBU);
    run_tests("OPT", lengthOfLISOPT);
    run_tests("OPT2", lengthOfLISOPT2);

    print_report();
    return 0;
}