class Solution {
public:
    int n;
    long long helper(vector<int>& nums, int index, bool flag, vector<vector<long long>> &dp){
        if(index>=n){
            return 0;
        }

        if(dp[index][flag] != -1 ){
            return dp[index][flag];
        }

        long long splitthearray = nums[index]+helper(nums, index+1, false, dp);
        long long notsplitthearray = flag==true?(-1*nums[index]+helper(nums, index+1, false, dp)):(nums[index]+helper(nums, index+1, true, dp));

        return dp[index][flag]=max(notsplitthearray, splitthearray);

    }
    long long maximumTotalCost(vector<int>& nums) {
        n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return helper(nums, 0, false, dp);
    }
};

//pure dp
// class Solution {
// public:
//     long long maximumTotalCost(vector<int>& nums) {
//         int n = nums.size();
//         vector<long long> dp(n + 1, -LLONG_MAX);
//         dp[0] = 0;
//         dp[1] = nums[0];
//         for (int i = 1; i < n; ++i) {
//             dp[i + 1] = max(dp[i] + nums[i], dp[i - 1] + nums[i - 1] - nums[i]);
//         }
//         return dp[n];
//     }
// };