class Solution:
    def longestSubarray(self, arr, k):  
        # code here
        mpp = {}
        mpp[0] = -1
        sum = 0
        ans = 0
        for i in range(len(arr)) :
            sum+=arr[i]
            if sum not in mpp :
                mpp[sum] = i
            if sum-k in mpp :
                ans = max(ans,i-mpp[sum-k])
        
        return ans   
