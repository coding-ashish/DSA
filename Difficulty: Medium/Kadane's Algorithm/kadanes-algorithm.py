class Solution:
    def maxSubarraySum(self, arr):
        # Code here
        sum = 0
        ans = float('-inf')
        for i in arr:
            if sum < 0:
                sum = 0
            sum+=i
            ans = max(ans,sum)
            
        return ans    