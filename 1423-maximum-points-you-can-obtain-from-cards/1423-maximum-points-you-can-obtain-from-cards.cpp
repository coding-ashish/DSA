class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int sum = 0;
        int win_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i <= nums.size() - k-1)
                win_sum += nums[i];
            sum += nums[i];
        }

        if (k == nums.size()) {
            return sum;
        }

        int i = 0;
        int j = nums.size() - k-1;
        int mn = win_sum;

        while (j < nums.size() - 1) {
            if (win_sum < mn) {
                mn = win_sum;
            }
            win_sum -= nums[i];
            win_sum += nums[j + 1];
            i++;j++;
        }
        if (win_sum < mn) {
            mn = win_sum;
        }

        return sum-mn;
    }
};