class Solution {
public:
    string smallestPalindrome(string s, long long k) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int halfLen = n / 2;
        char midChar = 0;
        vector<int> halfCnt(26, 0);
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) midChar = 'a' + i;
            halfCnt[i] = cnt[i] / 2;
        }

        auto combCapped = [](long long N, long long R, long long cap) -> long long {
            if (R < 0 || R > N) return 0;
            R = min(R, N - R);
            long long res = 1;
            for (long long i = 1; i <= R; i++) {
                res = res * (N - R + i) / i;
                if (res > cap) return cap + 1;
            }
            return res;
        };
        auto permCountCapped = [&](vector<int>& counts, int totalLen, long long cap) -> long long {
            long long result = 1;
            long long remaining = totalLen;
            for (int i = 0; i < 26; i++) {
                int c = counts[i];
                if (c == 0) continue;
                result *= combCapped(remaining, c, cap);
                if (result > cap) return cap + 1;
                remaining -= c;
            }
            return result;
        };

        long long total = permCountCapped(halfCnt, halfLen, k);
        if (k > total) return "";

        long long remainingK = k - 1;
        vector<int> counts = halfCnt;
        int remainingLen = halfLen;
        string half;
        half.reserve(halfLen);

        for (int pos = 0; pos < halfLen; pos++) {
            for (int i = 0; i < 26; i++) {
                if (counts[i] == 0) continue;
                counts[i]--;
                long long cntPerms = permCountCapped(counts, remainingLen - 1, remainingK);
                if (remainingK < cntPerms) {
                    half.push_back('a' + i);
                    remainingLen--;
                    break;
                } else {
                    remainingK -= cntPerms;
                    counts[i]++;
                }
            }
        }

        string result = half;
        if (midChar) result.push_back(midChar);
        for (int i = half.size() - 1; i >= 0; i--) result.push_back(half[i]);

        return result;
    }
};