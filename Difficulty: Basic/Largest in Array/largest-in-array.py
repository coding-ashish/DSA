class Solution:
    def largest(self, arr):
        # code here
        mx = float('-inf')
        for i in range(len(arr)):
            mx = max(mx,arr[i])
        
        return mx
