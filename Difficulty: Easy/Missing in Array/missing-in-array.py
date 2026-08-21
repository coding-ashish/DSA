class Solution:
    def missingNum(self, arr):
        # code here
        n = len(arr)+1
        # sum = 0
        sum = n*(n+1)//2
        
        sm = 0
        for i in arr :
            sm += i
            
        return sum - sm