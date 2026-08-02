class Solution {
public:
    bool predictTheWinner(vector<int>& piles) {
        // int s1 = score1()
        int scr = score(piles,0,piles.size()-1,true);

        int sum = 0;
        for (int i = 0; i < piles.size(); i++) {
            sum += piles[i];
        }

        return scr >= (sum - scr);
    }

    int score(vector<int>& piles, int i, int j, bool scor) {
        if (!scor) {
            return min(score(piles, i + 1, j, true),
                       score(piles, i, j - 1, true));
        }

        if (i > j) {
            return 0;
        }

        return max(piles[i] + score(piles, i + 1, j, false),
                   piles[j] + score(piles, i, j - 1, false));
    }
};