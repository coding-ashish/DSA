#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // Memoization table: -1 = unvisited, 0 = false (loss), 1 = true (win)
    vector<int> memo;

    bool solve(int n) {
        // Base case: 0 stones left means the player has no moves and loses
        if (n == 0) return false;

        // Return cached result if already calculated
        if (memo[n] != -1) return memo[n];

        // Try removing every possible square number k*k
        for (int k = 1; k * k <= n; ++k) {
            // If making this move forces the opponent into a losing state
            if (!solve(n - k * k)) {
                return memo[n] = 1; // Current player wins
            }
        }

        // If no square move leads to a win, current player loses
        return memo[n] = 0;
    }

public:
    bool winnerSquareGame(int n) {
        // Initialize memo vector with -1
        memo.assign(n + 1, -1);
        return solve(n);
    }
};