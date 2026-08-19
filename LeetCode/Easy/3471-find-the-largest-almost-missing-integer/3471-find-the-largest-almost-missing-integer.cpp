class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        if (k == n) {
            int ans = -1;
            for (int i = 0; i < n; i++) {
                if (nums[i] > ans) {
                    ans = nums[i];
                }
            }
            return ans;
        }
        
        int count[51] = {0};
        for (int i = 0; i < n; i++) {
            count[nums[i]]++;
        }
        
        if (k == 1) {
            int ans = -1;
            for (int i = 0; i <= 50; i++) {
                if (count[i] == 1) {
                    if (i > ans) {
                        ans = i;
                    }
                }
            }
            return ans;
        }
        
        int ans = -1;
        if (count[nums[0]] == 1) {
            ans = nums[0];
        }
        if (count[nums[n - 1]] == 1) {
            if (nums[n - 1] > ans) {
                ans = nums[n - 1];
            }
        }
        
        return ans;
    }
};