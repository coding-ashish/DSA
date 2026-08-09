class Solution {
public:
    int memo[101][101];

    int solve(int i, int M, vector<int>& piles) {
        int n = piles.size();

        // Base case: If no piles left, return 0
        if (i >= n) return 0;

        // Return cached answer if already calculated
        if (memo[i][M] != -1) return memo[i][M];

        int currentTake = 0;
        int maxStones = 0;

        // Try taking X piles (where 1 <= X <= 2 * M)
        for (int X = 1; X <= 2 * M; X++) {
            if (i + X - 1 >= n) break; // Beyond array bounds

            currentTake += piles[i + X - 1]; // Stones collected in current turn

            // Remaining stones Alice can get = (Total remaining stones) - (Stones opponent will get)
            // But simply: opponent gets solve(i + X, max(M, X), piles)
            // So total stones from here = currentTake + (Total rest - opponent's best)
            // An easier way:
            int nextM = max(M, X);
            
            // Calculate total stones left from index i + X
            int totalRemaining = 0;
            for (int k = i + X; k < n; k++) {
                totalRemaining += piles[k];
            }

            int opponentStones = solve(i + X, nextM, piles);
            int myStones = currentTake + (totalRemaining - opponentStones);

            maxStones = max(maxStones, myStones);
        }

        return memo[i][M] = maxStones;
    }

    int stoneGameII(vector<int>& piles) {
        // Fill memo table with -1
        memset(memo, -1, sizeof(memo));

        // Start from index 0 with M = 1
        return solve(0, 1, piles);
    }
};