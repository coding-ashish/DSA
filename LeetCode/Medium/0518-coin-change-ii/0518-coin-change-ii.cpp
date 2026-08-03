class Solution {
public:
    int change(int amount, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(nums,0,amount,dp);
    }

    int solve(vector<int> &nums, int i, int amount,vector<vector<int>> &dp){
        int n = nums.size();
        if(i >= n){
            if(amount == 0){
                return 1;
            }else return  0;
        }
        if(amount==0){
            return 1;
        }
        else if(amount<0){
            return 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];

        return dp[i][amount] = solve(nums,i,amount-nums[i],dp) + solve(nums,i+1,amount,dp);
    }
};