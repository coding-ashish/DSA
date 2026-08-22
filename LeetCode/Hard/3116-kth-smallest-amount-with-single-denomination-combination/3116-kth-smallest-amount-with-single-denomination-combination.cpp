class Solution {
    long long get_gcd(long long a, long long b) {
        while (b > 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long get_lcm(long long a, long long b) {
        return a / get_gcd(a, b) * b;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long l = 1;
        long long r = 100000000000LL;
        
        while (l < r) {
            long long mid = l + (r - l) / 2;
            long long cnt = 0;
            int n = coins.size();
            
            for (int i = 1; i < (1 << n); ++i) {
                long long current_lcm = 1;
                int bits = 0;
                bool valid = true;
                
                for (int j = 0; j < n; ++j) {
                    if ((i >> j) & 1) {
                        bits++;
                        current_lcm = get_lcm(current_lcm, coins[j]);
                        if (current_lcm > mid) {
                            valid = false;
                            break;
                        }
                    }
                }
                
                if (valid) {
                    if (bits % 2 == 1) {
                        cnt += mid / current_lcm;
                    } else {
                        cnt -= mid / current_lcm;
                    }
                }
            }
            
            if (cnt >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return l;
    }
};