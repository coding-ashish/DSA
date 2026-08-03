class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2001,INT_MIN));
        return dp[0][1000] = solve(nums,0,0,target,dp);
    }

    int solve(vector<int> &nums, int i, int sum, int target, vector<vector<int>> &dp){
        int n = nums.size();
        if(i == n){
            if(sum==target){
                return 1;
            }else return 0;
        }
        if(dp[i][sum+1000]!=INT_MIN){
            return dp[i][sum+1000];
        }

        return dp[i][sum+1000] = solve(nums,i+1,sum+nums[i],target,dp) + solve(nums,i+1,sum-nums[i],target,dp);
    }
};