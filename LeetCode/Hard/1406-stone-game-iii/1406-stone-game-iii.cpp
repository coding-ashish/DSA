class Solution {
public:
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, INT_MIN);

        int res = solve(nums, 0, dp);
        if (res > 0)
            return "Alice";
        else if (res == 0)
            return "Tie";
        else
            return "Bob";
    }

    int solve(vector<int>& nums, int i, vector<int>& dp) {
    if (i >= nums.size())
        return 0;

    if (dp[i] != INT_MIN)
        return dp[i];

    int ans = INT_MIN;
    int take = 0;

    for (int k = 0; k < 3 && i + k < nums.size(); k++) {
        take += nums[i + k];
        ans = max(ans, take - solve(nums, i + k + 1, dp));
    }

    return dp[i] = ans;
}
};