class Solution {
public:
    bool predictTheWinner(vector<int>& piles) {
        // int s1 = score1()
        vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),-1));
        // dp.assign(piles.size()-1,vector<int>(piles.size()-1,-1));
        dp[0][piles.size()-1] = score(piles,0,piles.size()-1,true,dp);

        int sum = 0;
        for (int i = 0; i < piles.size(); i++) {
            sum += piles[i];
        }

        return dp[0][piles.size()-1] >= (sum - dp[0][piles.size()-1]);
    }

    int score(vector<int>& piles, int i, int j, bool scor,vector<vector<int>> &dp) {
        if (!scor) {
            return min(score(piles, i + 1, j, true,dp),
                       score(piles, i, j - 1, true,dp));
        }

        if (i > j) {
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        return dp[i][j] = max(piles[i] + score(piles, i + 1, j, false,dp),
                   piles[j] + score(piles, i, j - 1, false,dp));
    }
};