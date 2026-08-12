class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int i = 0;
        int j = 0;
        int n = nums.size();

        int maxlen = 0;
        while(j<n){
            mpp[nums[j]]++;
            while(mpp[nums[j]]>k){
                maxlen = max(j-i,maxlen);
                mpp[nums[i]]--;
                i++;
            }
            
            j++;

        }

        maxlen = max(maxlen,j-i);
        return maxlen;
    }
};