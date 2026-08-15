class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int zor = 0;
        bool isZeroArray = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                isZeroArray = false;
            zor = zor ^ nums[i];
        }
        if (zor!= 0) {
            return nums.size();
        } else if(isZeroArray) return 0;
        else {
            return nums.size()-1;
        }
    }
};