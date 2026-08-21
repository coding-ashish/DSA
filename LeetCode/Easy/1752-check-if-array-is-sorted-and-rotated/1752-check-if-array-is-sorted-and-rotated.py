class Solution:
    def check(self, nums: List[int]) -> bool:
        cnt = 0
        for i in range(len(nums)-1):
            if nums[i] > nums[i+1] :
                cnt+=1
            if cnt > 1 :
                return False
    
        if nums[len(nums)-1] > nums[0] and cnt == 1:
            return False
        
        return True