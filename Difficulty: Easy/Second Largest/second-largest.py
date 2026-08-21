class Solution:
    def getSecondLargest(self, arr):
        # code here
        mx = -1
        s_mx = -1
        
        for i in arr:
            if i > mx :
                s_mx = mx
                mx = i
            elif i > s_mx and i != mx :
                s_mx = i
                
        
        return s_mx
            