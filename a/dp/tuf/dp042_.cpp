#include <string>
#include <vector>
using namespace std;

void print_arrays(int, vector<int>&, vector<int> &, vector<int>&);

string BF(int idx, int last_idx, vector<int>& nums) {
    const int N = (int) nums.size();
    if (idx==0) return "";

    string res=BF(idx-1, last_idx, nums); // SKIPPED
    bool can_pick = (last_idx==N+1) || nums[idx-1]<nums[last_idx-1];
    if (can_pick) {
        string pick=BF(idx-1, idx, nums) + " " + to_string(nums[idx-1]);
        if (pick.size() > res.size()) res=pick;
    }
    return res;
}

string printLISBF(vector<int>& nums) {
    const int N = (int) nums.size();
    return BF(N, N+1, nums);
}


string printLISDP(vector<int>& nums) {
    const int N = (int) nums.size();
    vector<int> dp (N, 1); // min: just the num itself

    // everyone's parent is zero
    vector<int> par(N+1, 0); // 1 based

    if (nums.empty()) return "";
    int lastPar=1;
    for (int i=0; i<N; i++) {  // each num
        // check each prev num
        for (int j=0; j<i; j++) {
            if (nums[j] < nums[i]) {
                if (1+dp[j] > dp[i]) { // new max
                    dp[i]=1+dp[j];
                    // bigger sequence from this number
                    par[i+1]=j+1;
                    lastPar=i+1;
                }

            }
        }
    }

    // print_arrays(N, nums, dp, par);

    string res;
    while (lastPar!=0) {
        res = to_string(nums[lastPar-1]) + " " + res;
        lastPar=par[lastPar];
    }
    return res;
}



#include "test/dp042.h"
int main() {
    run_tests("BF", printLISBF);
    run_tests("DP", printLISDP);

    print_report();
    return 0;
}