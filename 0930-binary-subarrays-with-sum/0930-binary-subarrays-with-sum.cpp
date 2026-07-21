class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return function(nums, goal) - function(nums, goal - 1);
    }

    int function(vector<int>& nums, int goal) {
        if(goal<0) return 0;
        int i = 0;
        int sum = 0;
        int ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            if (sum <= goal) {
                ans += j - i + 1;
            } else {
                while (sum > goal) {
                    sum -= nums[i];
                    i++;
                }
                ans+= j-i+1;
            }
        }
        return ans;
    }
};