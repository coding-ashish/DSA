class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return function(nums,k) - function(nums,k-1);
    }

    int function(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int i = 0;
        int cnt = 0;
        int ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] % 2 == 1)
                cnt++;
            if (cnt <= goal) {
                ans += j - i + 1;
            } else {
                while (cnt > goal) {
                    if(nums[i]%2==1){
                        cnt--;
                    }
                    i++;
                }
                ans += j - i + 1;
            }
        }
        return ans;
    }
};