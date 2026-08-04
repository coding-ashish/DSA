class Solution {
	public:
	int cutRod(vector<int> &price) {
		// code here
		int n = price.size();
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
		
		return solve(price, 0, n, dp);
	}
	
	int solve(vector<int> &price, int i, int n, vector<vector<int>> &dp) {
		if (n == 0) {
			return 0;
		}
		if (n<0) {
			return INT_MIN;
		}
		if (i >= price.size())
			return INT_MIN;
		if (dp[i][n] != -1) {
			return dp[i][n];
		}
		
		return dp[i][n] = max(price[i] + solve(price, i, n - i-1, dp), solve(price, i + 1, n, dp));
	}
};
