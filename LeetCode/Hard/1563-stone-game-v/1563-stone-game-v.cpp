class Solution {
public:
    int solve(int i, int j, const vector<int>& prefix, vector<vector<int>>& memo) {
        if (i == j) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int max_score = 0;
        
        for (int k = i; k < j; ++k) {
            int left_sum = prefix[k + 1] - prefix[i];
            int right_sum = prefix[j + 1] - prefix[k + 1];

            if (left_sum < right_sum) {
                max_score = max(max_score, left_sum + solve(i, k, prefix, memo));
            } else if (left_sum > right_sum) {
                max_score = max(max_score, right_sum + solve(k + 1, j, prefix, memo));
            } else {
                max_score = max(max_score, left_sum + max(solve(i, k, prefix, memo), solve(k + 1, j, prefix, memo)));
            }
        }
        
        return memo[i][j] = max_score;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        
        vector<vector<int>> memo(n, vector<int>(n, -1));
        
        return solve(0, n - 1, prefix, memo);
    }
};