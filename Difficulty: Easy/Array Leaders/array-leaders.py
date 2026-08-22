class Solution:
    
    def reverse(self,ans) :
        i = 0
        j = len(ans)-1
            
        while i<j :
            ans[i],ans[j] = ans[j],ans[i]
            i+=1
            j-=1
        return
        
            
    def leaders(self, arr):
        # code here
        ans = []
        i = len(arr)-1-1
        mx = arr[len(arr)-1]
        ans.append(arr[len(arr)-1])
        while(i>=0):
            if(arr[i] >= mx):
                mx = arr[i]
                ans.append(arr[i])
            i-=1
        
        self.reverse(ans)
        return ans